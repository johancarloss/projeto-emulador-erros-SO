/*
- runner.c

- Menu para executar os programas de erro já compilados.
- Verifica se o executável existe antes de rodar.
- Funciona com todos os arquivos listados no projeto.

- Compilar:
- gcc runner/runner.c -o output/runner

- Executar:
- ./output/runner
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // para acess()

#define PATH_SIZE 256

// Função para checar se um arquivo existe
int arquivo_existe(const char *path) {
  return access(path, F_OK) != -1;
}

// Função que tenta executar um programa
void executar_programa(const char *nome_exec) {
  char caminho[PATH_SIZE];

  #ifdef _WIN32
    #define EXE_EXT ".exe"
  #else
    #define EXE_EXT ""
  #endif

  // monta o caminho correto para executáveis na pasta output
  snprintf(caminho, sizeof(caminho), "./output/%s%s", nome_exec, EXE_EXT);

  if (arquivo_existe(caminho)) {
    printf("\nExecutando %s...\n\n", nome_exec);
    char cmd[PATH_SIZE];
    snprintf(cmd, sizeof(cmd), "%s", caminho);
    system(cmd);
  } else {
    printf("\n[ERRO] Executavel '%s' nao encontrado!\n", nome_exec);
  }
}

int main() {
  int opcao;

  while (1) {
    printf("\n====================================\n");
    printf("      EMULADOR DE ERROS - RUNNER\n");
    printf("====================================\n");
    printf("1  - Memory Leak\n");
    printf("2  - Race Condition\n");
    printf("3  - Deadlock\n");
    printf("4  - Segmentation Fault\n");
    printf("5  - Core Dump\n");
    printf("6  - Stack Overflow\n");
    printf("7  - Buffer Overflow\n");
    printf("8  - Sair\n");
    printf("Escolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) {
      int c;
      while((c = getchar()) != '\n' && c != EOF);
      printf("Entrada invalida. Digite um numero.\n");
      continue;
    }

    switch (opcao) {
      case 1: executar_programa("memory_leak"); break;
      case 2: executar_programa("race_condition"); break;
      case 3: executar_programa("deadlock"); break;
      case 4: executar_programa("segfault"); break;
      case 5: executar_programa("core_dump"); break;
      case 6: executar_programa("stack_overflow"); break;
      case 7: executar_programa("buffer_overflow"); break;
      case 8:
        printf("Saindo...\n");
        return 0;
      default:
        printf("Opcao invalida.\n");
    }
  }
}