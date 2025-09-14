/*
- memory_leak.c

- Demonstra um Memory Leak.
- Cenário: cadastro de usuários com alocação dinâmica que nunca é liberada.
- Cada vez que a função é chamada, a memória é alocada mas não liberada.

- Para compilar:
- gcc erros/memory_leak.c -o output/memory_leak

- Para executar:
- ./memory_leak
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // para sleep

// Estrutura simples para armazenar dados de usuário
typedef struct {
  char nome[50];
  int idade;
  char buffer[1000000]; // 1MB por usuário
} Usuario;

// Variável global para contar memória total alocada
size_t memoria_total = 0;

// Função que causa Memory Leak
void causar_memory_leak(int vezes) {
  for (int i = 0; i < vezes; i++) {
    // Aloca memória dinamicamente
    Usuario *u = (Usuario*)malloc(sizeof(Usuario));
    if (!u) {
      printf("Falha na localizacao de memoria!\n");
      break;
    }

    memoria_total += sizeof(Usuario); // contabiliza memoria

    // Simula preenchimento de dados
    snprintf(u->nome, sizeof(u->nome), "Usuario_%d", i);
    u->idade = 20 + (i % 10);
    
    printf("Cadastro criado: %s, idade %d | Memoria usada (estimada): %zu bytes\n", 
      u->nome, u->idade, memoria_total);

    // NOTA: NÃO estamos liberando a memória: free(u);
    // Isso causa um Memory Leak crescente a cada iteração
    sleep(1); // pausa para visualização gradual
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