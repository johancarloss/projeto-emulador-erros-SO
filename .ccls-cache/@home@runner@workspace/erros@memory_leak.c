/*
- memory_leak.c

- Demonstração de Memory Leak (vazamento de memória).
- Cenário: cadastro de usuários com alocação dinâmica que nunca é liberada.
  Cada vez que a função é chamada, a memória é alocada mas não liberada,
  aumentando gradualmente o consumo de memória do programa.

- Para compilar:
  gcc erros/memory_leak.c -o output/memory_leak

- Para executar:
  .output/memory_leak

- Observação:
  O Memory Leak é intencional para fins didáticos.
  Rodar muitas iterações pode consumir bastante memória do sistema.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // para sleep

// Estrutura simples para armazenar dados de usuário
typedef struct {
  char nome[50];
  int idade;
  char buffer[1000000]; // 1MB por usuário para tornar o leak visível rapidamente
} Usuario;

// Variável global para ccontabilizar memória alocada (estimada)
size_t memoria_total = 0;

// Função que causa Memory Leak
void causar_memory_leak(int vezes) {
  for (int i = 0; i < vezes; i++) {
    // Aloca memória dinamicamente para cada usuário
    Usuario *u = (Usuario*)malloc(sizeof(Usuario));
    if (!u) {
      printf("Falha na localizacao de memoria!\n");
      break;
    }

    // Atualiza o contador de memória total
    memoria_total += sizeof(Usuario);

    // Preenche os dados do usuário
    snprintf(u->nome, sizeof(u->nome), "Usuario_%d", i);
    u->idade = 20 + (i % 10);
    
    printf("Cadastro criado: %s, idade %d | Memoria usada (estimada): %zu bytes\n", 
      u->nome, u->idade, memoria_total);

    // NOTA: NÃO estamos liberando a memória: free(u);
    // Isso é intencional para demonstrar o Memory Leak

    sleep(1); // Pausa para visualização gradual do consumo de memória
  }
}

// Função main apenas para teste isolado
int main() {
  printf("Iniciando demonstracao de Memory Leak...\n");

  // Chama a função para criar 10 usuários
  causar_memory_leak(10);

  printf("Execucao finalizada. Memoria nao foi liberada!\n");
  
  return 0;
}