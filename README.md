# Emulador de Erros de Sistema Operacional

## Descrição do Projeto

Este projeto tem como objetivo **simular e demonstrar diversos erros de programação e problemas comuns em sistemas operacionais**, permitindo que alunos ou interessados observem, de forma prática, o comportamento de códigos que geram erros como Memory Leak, Race Condition, Deadlock, entre outros.

O projeto é escrito em **C** e estruturado de forma organizada para facilitar a compilação e execução dos exemplos de erro.

## Estrutura do Projeto

O projeto possui a seguinte estrutura de pastas:

```
projeto-emulador-erros-SO/
├─ erros/                 # Contém os códigos de demonstração de erros (.c)
├─ output/                # Pasta onde os executáveis compilados serão gerados (criada pelo run.sh)
├─ runner/                # Contém runner.c e run.sh para compilar e executar os erros
```

### Pastas e Arquivos

* **erros/**: arquivos `.c` de demonstração de cada erro (Memory Leak, Race Condition, Deadlock, etc.)
* **output/**: criada automaticamente pelo `run.sh`, receberá os executáveis compilados
* **runner/**: contém `runner.c` (menu interativo) e `run.sh` (script bash de compilação)
* **runner/run.sh**: script que compila todos os arquivos `.c` dentro de `erros/` e o `runner.c`, gerando executáveis na pasta `output/`

## Erros Implementados

Os erros já implementados e funcionando são:

| Erro           | Descrição                                                                       |
| -------------- | ------------------------------------------------------------------------------- |
| Memory Leak    | Demonstra alocação de memória que nunca é liberada                              |
| Race Condition | Demonstra condições de corrida entre threads acessando um recurso compartilhado |
| Deadlock       | Demonstra deadlock entre threads ao tentar adquirir recursos simultaneamente    |

Outros erros ainda não implementados completamente, mas incluídos no runner:

* Segmentation Fault
* Core Dump
* Stack Overflow
* Buffer Overflow

> Obs: Se algum executável ainda não existir, o runner exibirá mensagem de erro apropriada.

## Como Compilar e Executar

### 1. Tornar o script `run.sh` executável

No Linux, abra o terminal na raiz do projeto e execute:

```bash
chmod +x runner/run.sh
```

### 2. Compilar todos os erros e o runner

```bash
./runner/run.sh
```

O script realiza as seguintes ações:

* Cria a pasta `output/` caso ainda não exista
* Compila todos os arquivos `.c` da pasta `erros/`
* Compila `runner/runner.c`
* Gera todos os executáveis na pasta `output/`

### 3. Executar o Runner

Após a compilação, execute:

```bash
./output/runner
```

O runner exibirá um menu interativo com todas as opções de erro implementadas, verificando se o executável correspondente existe antes de tentar executá-lo.

## Observações

* O projeto é desenvolvido para Linux. Também é possível compilar no Windows usando MinGW, neste caso os executáveis recebem a extensão `.exe`.
* O Makefile não é utilizado atualmente; toda a compilação é feita pelo `run.sh`. Ele poderá ser útil futuramente caso haja integração com Docker ou automação de build.
* A execução de alguns erros, como Deadlock ou Memory Leak, pode travar ou afetar o sistema se não forem encerrados corretamente. Utilize com cautela.

## Próximos Passos

* Implementar os erros restantes: Segmentation Fault, Core Dump, Stack Overflow, Buffer Overflow
* Melhorar a interface do runner (cores, formatação)
* Integrar o projeto com Docker para facilitar testes em ambientes controlados