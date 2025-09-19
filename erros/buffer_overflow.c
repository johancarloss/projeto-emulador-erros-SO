/*
- buffer_overflow.c

- Demonstração didática de Buffer Overflow (estouro de buffer na stack)
- Objetivo: mostrar passo-a-passo como escrever além do limite do buffer
  pode alterar uma variável adjacente na stack. A alteração é feita byte-a-byte
  para que a turma veja a progressão (sem depender de input externo).

- Para compilar:
  gcc erros/buffer_overflow.c -o output/buffer_overflow

- Para executar:
  ./output/buffer_overflow
*/

#include <stdio.h>
#include <unistd.h>  // sleep
#include <stdint.h>  // uint8_t
#include <string.h>

void demonstrar_buffer_overflow(void) {
    char buffer[16];                      // buffer intencionalmente pequeno
    int variavel_adjacente = 0xABCDEF01;  // "canary" demonstrativo (será sobrescrito byte-a-byte)

    /* Limpa o buffer para leitura limpa */
    memset(buffer, 0, sizeof(buffer));

    printf("Iniciando demonstracao de Buffer Overflow (escrita controlada)...\n");
    printf("Valor inicial da variavel_adjacente: 0x%x\n", variavel_adjacente);
    fflush(stdout);

    /* Vamos escrever byte-a-byte: primeiro dentro do buffer, depois em bytes da variavel adjacente */
    /* Observação: usamos escrita dirigida para demonstrar claramente a corrupção da variável adjacente. */
    uint8_t *p_buffer = (uint8_t *)buffer;
    uint8_t *p_canary_bytes = (uint8_t *)&variavel_adjacente;

    /* Quantidade total de bytes que escreveremos (mais que o buffer para provocar overflow) */
    int total_bytes = sizeof(buffer) + (int)sizeof(variavel_adjacente);

    for (int i = 0; i < total_bytes; i++) {
        if (i < (int)sizeof(buffer)) {
            /* Escreve dentro do buffer */
            p_buffer[i] = 'A' + (i % 26);
            printf("Escrevendo buffer[%2d] = '%c'\n", i, p_buffer[i]);
        } else {
            /* Escreve nos bytes de variavel_adjacente, simulando overflow controlado */
            int idx = i - (int)sizeof(buffer);
            p_canary_bytes[idx] = 'a' + (idx % 26);
            printf(" * Overflow: sobrescrevendo byte %d da variavel_adjacente\n", idx);
        }
        fflush(stdout);
        sleep(1); /* pausa para visualização na sala */
    }

    /* Mostra o resultado final */
    printf("\nDepois da escrita:\n");
    printf("  variavel_adjacente (hex) = 0x%x\n", variavel_adjacente);
    printf("  Conteudo (resumido) do buffer: %.16s\n", buffer);
    fflush(stdout);
}

int main(void) {
    demonstrar_buffer_overflow();
    printf("\nExecucao finalizada da demonstracao de Buffer Overflow.\n");
    return 0;
}
