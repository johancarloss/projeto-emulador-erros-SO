/*
- runner.c

- Menu aprimorado para executar os programas de erro já compilados.
- Verifica se o executável existe antes de rodar.
- Funciona com todos os arquivos listados no projeto.
- Adicionadas melhoreias visuais e funcionais:
    * Cores no menu
    * Descrições rápidos dos erros
    * Confirmação de saída
    * Limpeza da tela entre execuções
    * Pausa após execução
    * Contador de execuções por erro
    
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

// Funções auxiliares de cor ANSI
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_RESET "\x1b[0m"

// Contadores de execução
int contador_memory_leak = 0;
int contador_race_condition = 0;
int contador_deadlock = 0;
int contador_segfault = 0;
int contador_core_dump = 0;
int contador_stack_overflow = 0;
int contador_buffer_overflow = 0;

// Função para checar se um arquivo existe
int arquivo_existe(const char *path) {
  return access(path, F_OK) != -1;
}

// Função que tenta executar um programa
void executar_programa(const char *nome_exec, const char *descricao, int *contador) {
  char caminho[PATH_SIZE];

  #ifdef _WIN32
    #define EXE_EXT ".exe"
  #else
    #define EXE_EXT ""
  #endif

  // monta o caminho correto para executáveis na pasta output
  snprintf(caminho, sizeof(caminho), "./output/%s%s", nome_exec, EXE_EXT);

  if (arquivo_existe(caminho)) {
    printf("\n%sExecutando %s...%s\n", ANSI_GREEN, nome_exec, ANSI_RESET);
    printf("%s\n\n", descricao);
    char cmd[PATH_SIZE];
    snprintf(cmd, sizeof(cmd), "%s", caminho);
    system(cmd);
    (*contador)++; // incrementa contador de execução
    printf("\nPressione ENTER para continuar...");
    getchar(); getchar(); // pausa até o usuário pressionar ENTER
  } else {
    printf("\n%s[ERRO]%s Executavel '%s' nao encontrado!\n", ANSI_RED, ANSI_RESET, nome_exec);
    printf("\nPressione ENTER para continuar...");
    getchar(); getchar();
  }
}

// Função para limpar a tela
void limpar_tela() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int main() {
  int opcao;
  int sair = 0;

  while (!sair) {
    limpar_tela();
    printf("====================================\n");
    printf("      EMULADOR DE ERROS - RUNNER\n");
    printf("====================================\n");
    printf(ANSI_GREEN "1  - Memory Leak (executado %d vezes)\n" ANSI_RESET, contador_memory_leak);
    printf(ANSI_GREEN "2  - Race Condition (executado %d vezes)\n" ANSI_RESET, contador_race_condition);
    printf(ANSI_GREEN "3  - Deadlock (executado %d vezes)\n" ANSI_RESET, contador_deadlock);
    printf(ANSI_YELLOW "4  - Segmentation Fault (em desenvolvimento)\n" ANSI_RESET);
    printf(ANSI_YELLOW "5  - Core Dump (em desenvolvimento)\n" ANSI_RESET);
    printf(ANSI_YELLOW "6  - Stack Overflow (em desenvolvimento)\n" ANSI_RESET);
    printf(ANSI_YELLOW "7  - Buffer Overflow (em desenvolvimento)\n" ANSI_RESET);
    printf("8  - Sair\n");
    printf("Escolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) {
      int c;
      while((c = getchar()) != '\n' && c != EOF);
      printf("Entrada invalida. Digite um numero.\n");
      sleep(1);
      continue;
      }

    switch (opcao) {
      case 1:
        executar_programa("memory_leak",
                          "Este erro demonstra vazamento de memoria (Memory Leak).",
                          &contador_memory_leak);
        break;
      case 2:
        executar_programa("race_condition",
                          "Este erro demonstra uma condicaoo de corrida entre threads (Race Condition).",
                          &contador_race_condition);
              break;
      case 3:
        executar_programa("deadlock",
                          "Este erro demonstra deadlock entre threads ao tentar adquirir recursos simultaneamente.",
                          &contador_deadlock);
        break;
      case 4:
        executar_programa("segfault",
                            "Erro de Segmentação (Segmentation Fault).",
                            &contador_segfault);
        break;
      case 5:
        executar_programa("core_dump",
                          "Erro de Core Dump.",
                          &contador_core_dump);
        break;
      case 6:
        executar_programa("stack_overflow",
                          "Erro de Stack Overflow.",
                          &contador_stack_overflow);
        break;
      case 7:
        executar_programa("buffer_overflow",
                          "Erro de Buffer Overflow.",
                          &contador_buffer_overflow);
        break;
      case 8:
      {
        char confirma;
        printf("Tem certeza que deseja sair? (s/n): ");
        scanf(" %c", &confirma);
        if (confirma == 's' || confirma == 'S') {
          sair = 1;
        }
        break;
      }
      default:
        printf("Opcao invalida.\n");
        sleep(1);
      }
  }

  printf("\nSaindo do Runner. Ate mais!\n");
  return 0;
}