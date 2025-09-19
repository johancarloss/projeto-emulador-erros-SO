/*
- stack_overflow.c

- Demonstração didática de "Stack Overflow" (estouro de pilha)
- Objetivo: mostrar a progressão do consumo de stack de forma visual,
  imprimindo a profundidade em cada passo. Por padrão não explode a stack
  imediatamente — a ideia é demonstrar o processo passo-a-passo.
  Se quiser provocar o crash real, aumente MAX_DEPTH ou modifique o tamanho
  do BUFFER_SIZE.

- Para compilar:
  gcc erros/stack_overflow.c -o output/stack_overflow

- Para executar:
  ./output/stack_overflow
*/

#include <stdio.h>
#include <unistd.h> // sleep
#include <string.h>

#define BUFFER_SIZE 30000  // espaço alocado em cada frame (em bytes)
#define STEP_DEPTH 1       // incremento de profundidade por chamada
#define MAX_DEPTH 1000000      // número de níveis que iremos mostrar (didático)

void recursao_didatica(int depth) {
    /* Variável local grande para consumir espaço na stack. Volatile evita otimizações. */
    volatile char local_buffer[BUFFER_SIZE];
    /* Preenche para garantir ocupação efetiva da stack frame */
    memset((void*)local_buffer, (char)(depth & 0xFF), sizeof(local_buffer));

    /* Impressão didática para a apresentação */
    printf("Profundidade atual da recursao: %d (cada frame tem %d bytes)\n", depth, BUFFER_SIZE);
    fflush(stdout);

    /* Pausa curta para a turma ver o progresso */
    sleep(1);

    /* Condição didática para não travar a máquina durante a demo */
    if (depth < MAX_DEPTH) {
        recursao_didatica(depth + STEP_DEPTH);
    } else {
        printf("Alcançado limiar demonstrativo (%d). Voltando (nao forçando crash aqui)...\n", MAX_DEPTH);
        fflush(stdout);
    }

    /* Ao retornar, liberamos os frames e a stack "desce" novamente */
}

int main(void) {
    printf("Iniciando demonstracao didatica de Stack Overflow...\n");
    printf("Nota: esta demonstracao nao gera crash por padrao; aumenta MAX_DEPTH ou BUFFER_SIZE para testar comportamento real.\n\n");
    fflush(stdout);

    recursao_didatica(1);

    printf("\nExecucao finalizada (pilha liberada). Se quiser forcar o crash, ajuste MAX_DEPTH ou BUFFER_SIZE no codigo.\n");
    return 0;
}
