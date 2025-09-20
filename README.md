# 🚨 Emulador de Erros de Sistema Operacional

<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white)
![GitHub Actions](https://img.shields.io/badge/github%20actions-%232671E5.svg?style=for-the-badge&logo=githubactions&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

**Simulador educacional interativo para demonstração prática de erros críticos em sistemas operacionais**

[🐳 Docker Hub](https://hub.docker.com/r/johancarloss/projeto-emulador) • [📖 Documentação](#como-usar) • [🔧 Desenvolvimento](#desenvolvimento)

</div>

## 📋 Descrição do Projeto

Este projeto tem como objetivo **simular e demonstrar diversos erros de programação e problemas comuns em sistemas operacionais**, permitindo que alunos, desenvolvedores e interessados observem, de forma prática e controlada, o comportamento de códigos que geram erros críticos como:

- 🧠 **Memory Leak** - Vazamento de memória
- 🏃‍♂️ **Race Condition** - Condições de corrida
- 🔒 **Deadlock** - Bloqueio mútuo
- 💥 **Segmentation Fault** - Violação de segmento
- 📊 **Stack Overflow** - Estouro de pilha
- 🔓 **Buffer Overflow** - Estouro de buffer

O projeto é desenvolvido em **C** com foco educacional, proporcionando um ambiente seguro e controlado para observação desses comportamentos críticos.

## 🏗️ Estrutura do Projeto

```
projeto-emulador-erros-SO/
├── 📁 erros/                    # Demonstrações de erros em C
│   ├── memory_leak.c           # ✅ Vazamento de memória
│   ├── race_condition.c        # ✅ Condições de corrida
│   ├── deadlock.c              # ✅ Bloqueio mútuo
│   ├── buffer_overflow.c       # 🚧 Em desenvolvimento
│   ├── core_dump.c             # 🚧 Em desenvolvimento
│   ├── segfault.c              # 🚧 Em desenvolvimento
│   └── stack_overflow.c        # 🚧 Em desenvolvimento
├── 📁 runner/                   # Sistema de execução
│   ├── runner.c                # Menu interativo principal
│   └── run.sh                  # Script de compilação automática
├── 📁 docker/                   # Configuração de containerização
│   ├── Dockerfile              # Imagem Docker Ubuntu 22.04
│   └── entrypoint.sh           # Script de inicialização
├── 📁 .github/workflows/        # Automação CI/CD
│   └── docker-publish.yml      # Pipeline de build e publicação
├── 📁 output/                   # Executáveis compilados (auto-gerada)
└── 📄 README.md                 # Esta documentação
```

## ✅ Status dos Erros

### 🟢 Implementados e Funcionais

| Erro | Descrição | Comportamento | Threads |
|------|-----------|---------------|---------|
| 🧠 **Memory Leak** | Demonstra alocação de memória que nunca é liberada | Crescimento progressivo de 1MB por iteração | ❌ |
| 🏃‍♂️ **Race Condition** | Múltiplas threads acessam recurso compartilhado simultaneamente | Comportamento não-determinístico | ✅ |
| 🔒 **Deadlock** | Threads travadas esperando recursos umas das outras | Bloqueio completo do programa | ✅ |

### 🟡 Em Desenvolvimento

| Erro | Status | Próxima Release |
|------|--------|----------------|
| 💥 **Segmentation Fault** | 🚧 Estrutura criada | v2.0 |
| 🔓 **Buffer Overflow** | 🚧 Estrutura criada | v2.0 |
| 📊 **Stack Overflow** | 🚧 Estrutura criada | v2.0 |
| 💾 **Core Dump** | 🚧 Estrutura criada | v2.0 |

> ⚠️ **Aviso de Segurança**: Os erros implementados podem afetar o desempenho do sistema. Execute com cautela e em ambiente controlado.

## 🚀 Como Usar

### 🐳 Método 1: Docker (Recomendado)

A forma mais simples e segura de executar o projeto:

```bash
# Puxar a imagem mais recente do Docker Hub
docker pull johancarloss/projeto-emulador:latest
# Executar diretamente do Docker Hub
docker run -it --entrypoint /bin/bash johancarloss/projeto-emulador:latest
# O prompt vai mudar para algo como: root@<id_do_container>:/app#
# Depois disso só seguir o passo a passo presente no método 2
# a partir do método 2

# Ou construir localmente
docker build -f docker/Dockerfile -t emulador-erros .
docker run -it emulador-erros
```

**Vantagens do Docker:**
- ✅ Ambiente isolado e seguro
- ✅ Não afeta o sistema host
- ✅ Fácil limpeza após uso
- ✅ Consistência entre diferentes sistemas

### 💻 Método 2: Execução Local

#### Pré-requisitos
- GCC compiler
- Build tools (`build-essential` no Ubuntu/Debian)
- Sistema Linux ou WSL

#### Compilação e Execução

```bash
# 1. Clonar o repositório
git clone https://github.com/seu-usuario/projeto-emulador-erros-SO.git
cd projeto-emulador-erros-SO

# 2. Dar permissão de execução
chmod +x runner/run.sh

# 3. Compilar automaticamente
./runner/run.sh

# 4. Executar o menu interativo
./output/runner
```

### 🎮 Interface do Menu

Após a execução, você verá:

```
====================================
      EMULADOR DE ERROS - RUNNER
====================================
1  - Memory Leak
2  - Race Condition  
3  - Deadlock
4  - Segmentation Fault
5  - Core Dump
6  - Stack Overflow
7  - Buffer Overflow
8  - Sair
Escolha uma opcao: 
```

## 🐳 Docker & Containerização

### Configuração Docker

O projeto inclui configuração completa para containerização:

```dockerfile
# docker/Dockerfile
FROM ubuntu:22.04

# Instala dependências necessárias
RUN apt-get update && \
    apt-get install -y gcc build-essential make bash && \
    apt-get clean

WORKDIR /app
COPY . .
RUN chmod +x runner/run.sh
ENTRYPOINT ["./runner/run.sh"]
```

### Automação com GitHub Actions

Pipeline automatizado para build e publicação:

```yaml
# .github/workflows/docker-publish.yml
- Trigger: Push para main ou feature/docker-setup
- Build: Ubuntu latest com Docker Buildx  
- Publicação: Docker Hub (johancarloss/projeto-emulador)
- Segurança: Secrets gerenciados pelo GitHub
```

**Status da Pipeline**: 
- ✅ Build automatizado
- ✅ Publicação no Docker Hub
- ✅ Versionamento automático
- ✅ Secrets protegidos

## 🔧 Desenvolvimento

### Contribuindo

1. **Fork** o repositório
2. Crie sua branch: `git checkout -b feature/nova-funcionalidade`
3. **Desenvolva** e teste suas alterações
4. **Commit**: `git commit -m "Adiciona nova funcionalidade"`
5. **Push**: `git push origin feature/nova-funcionalidade`
6. Abra um **Pull Request**

### Estrutura de Desenvolvimento

```bash
# Para desenvolvimento local
./runner/run.sh              # Compila e testa
docker build -t test .       # Testa com Docker
docker run -it test          # Executa container de teste
```

### Possíveis Próximas Features (Roadmap)

- [ ] 🚧 **v2.0**: Implementar erros restantes
  - [ ] Segmentation Fault com análise de memória
  - [ ] Buffer Overflow com exemplos práticos  
  - [ ] Stack Overflow com recursão controlada
  - [ ] Core Dump com debugging info
- [ ] 🎨 **v2.1**: Interface melhorada
  - [ ] Cores no terminal
  - [ ] Logs detalhados
  - [ ] Modo educacional com explicações
- [ ] 🔐 **v2.2**: Recursos de segurança
  - [ ] Sandboxing avançado
  - [ ] Limitação de recursos
  - [ ] Timeouts automáticos

## 🎓 Uso Educacional

### Para Professores
- ✅ Ambiente seguro para demonstrações
- ✅ Isolamento via Docker
- ✅ Exemplos práticos de conceitos teóricos
- ✅ Facilidade de setup para laboratórios

### Para Estudantes  
- ✅ Observação prática de erros críticos
- ✅ Compreensão de comportamentos não-determinísticos
- ✅ Experiência hands-on com problemas reais
- ✅ Ambiente de aprendizado controlado

---

<div align="center">

**Desenvolvido com ❤️ para educação em Sistemas Operacionais**

[🐳 Docker Hub](https://hub.docker.com/r/johancarloss/projeto-emulador) • [🐛 Report Bug](../../issues) • [✨ Request Feature](../../issues)

</div>