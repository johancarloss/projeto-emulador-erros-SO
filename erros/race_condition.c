/*
- race_condition.c

- Demonstração de Race Condition (Condição de Corrida).
- Cenário: duas threads tentam sacar dinheiro de uma mesma conta bancária simultaneamente.
  Como não há sincronização, o saldo final pode variar a cada execução.

- Para compilar:
  gcc erros/race_condition.c -o output/race_condition -pthread

- Para executar:
  ./output/race_condition

- Observação:
  O resultado final pode variar a cada execução.
  Isso acontece porque as threas acessam o saldo compartilhado sem proteção (mutex),
  causando Race Condition intencional para fins didáticos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Saldo inicial da conta (recurso compartilhado)
int saldo = 100;

// Função executada por cada thread, simulando um saque
void* sacar(void* arg) {
  int valor = *(int*)arg; // valor a ser sacado
  int saldo_atual;

  // Lê o saldo
  saldo_atual = saldo;

  printf("[Thread %lu] Saldo Lido: %d, tentando sacar: %d\n", 
    pthread_self(), saldo_atual, valor);

  // Simula o atraso para aumentar a chance de Race Condition
  // Isso representa atrasos reais que podem ocorrer em sistemas multitarefa
  sleep(1);

  if (saldo_atual >= valor) {
    // Atualiza o saldo localmente
    saldo_atual -= valor;

    // Simula atraso antes de escrever o saldo de volta no recurso compartilhado
    sleep(1);
    saldo = saldo_atual;

    printf("[Thread %lu] Saque realizado. Novo saldo: %d\n", pthread_self(), saldo);
  } else {
    printf("[Thread %lu] Saldo insuficiente. Saque nao realizado.\n", pthread_self());
  }

  pthread_exit(NULL);
}

// Função principal que causa Race Condition
void causar_race_condition() {
  printf("Iniciando demonstracao de Race Condition...\n");

  pthread_t t1, t2;
  int valor_saque1 = 80;
  int valor_saque2 = 50;

  // Cria duas threads que tentam sacar simultaneamente
  pthread_create(&t1, NULL, sacar, &valor_saque1);
  pthread_create(&t2, NULL, sacar, &valor_saque2);

  // Aguarda as threads terminarem
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  // Saldo final pode variar a cada execução
  printf("Execucao finalizada. Saldo final: %d\n", saldo);
}

// Função main apenas para teste isolado
int main() {
  causar_race_condition();

  return 0;
}