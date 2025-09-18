/*
- deadlock.c

- Demonstração de Deadlock
- Cenário: duas threads tentam acessar dois recursos compartilhados (impressoras)
  simultaneamente, mas em ordem diferentes, causando deadlock.
  Cada thread pega uma impressora e tenta pegar a outra, podendo travar 
  indefinidamente.

- Para compilar:
  gcc erros/deadlock.c -o output/deadlock -pthread

- Para executar:
  ./output/deadlock

- Observação:
  As threads podem travar indefinidamente devido ao deadlock.
  É intencional para demonstração do problema.
  Use Ctrl+C para encerrar se travar
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Dois recursos (impressoras) representados por mutexes
pthread_mutex_t impressora1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t impressora2 = PTHREAD_MUTEX_INITIALIZER;

// Função executada por thread 1
void* thread1_func(void* arg) {
  printf("[Thread 1] Tentando pegar impressora 1...\n");
  pthread_mutex_lock(&impressora1); // Bloqueia impressora1
  printf("[Thread 1] Impressora 1 adquirida.\n");

  sleep(1); // Simula trabalho e dá chance para a outra thread executar, aumentando a chance de deadlock

  printf("[Thread 1] Tentando pegar impressora 2...\n");
  if(pthread_mutex_trylock(&impressora2) != 0) {
    // Tenta pegar impressora2, se não conseguir, bloqueia esperando
    printf("  - [Thread 1] Bloqueada esperando impressora 2...\n");
    pthread_mutex_lock(&impressora2);
  }
  printf("[Thread 1] Impressora 2 adquirida.\n");

  // Trabalho finalizado
  printf("[Thread 1] Impressao concluída.\n");

  // Nota: As próximas linhas de lock extra foram removidas, pois são redundantes
  // e nunca seriam alcançadas de forma segura.
  // pthread_mutex_lock(&impressora2);
  // pthread_mutex_lock(&impressora1);

  pthread_exit(NULL);
}

// Função executada por thread 2
void* thread2_func(void* arg) {
    printf("[Thread 2] Tentando pegar impressora 2...\n");
    pthread_mutex_lock(&impressora2); // Blolqueia a impressora2
    printf("[Thread 2] Impressora 2 adquirida.\n");

    sleep(1); // Simula trabalho e dá chance para a outra thread executar, aumentando a chance de deadlock

    printf("[Thread 2] Tentando pegar impressora 1...\n");
    if(pthread_mutex_trylock(&impressora1) != 0) {
      // Tenta pegar impressora1, se não conseguir, bloqueia esperando
      printf("  - [Thread 2] Bloqueada esperando impressora 1...\n");
      pthread_mutex_lock(&impressora1);
    }
    printf("[Thread 2] Impressora 1 adquirida.\n");

    // Trabalho finalizado
    printf("[Thread 2] Impressao concluída!\n");

    pthread_mutex_unlock(&impressora1);
    pthread_mutex_unlock(&impressora2);

    pthread_exit(NULL);
}

// Função principoal que causa Deadlock
void causar_deadlock() {
  printf("Iniciando demonstracao de Deadlock...\n");

  pthread_t t1, t2;

  pthread_create(&t1, NULL, thread1_func, NULL);
  pthread_create(&t2, NULL, thread2_func, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Execucao finalizada (se nao travou!)\n");
}

int main() {
  causar_deadlock();
  return 0;
}