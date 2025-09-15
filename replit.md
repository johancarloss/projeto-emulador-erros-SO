# Sistema de Demonstração de Erros de Sistema Operacional

## Visão Geral
Este projeto é um simulador educacional que demonstra diversos tipos de erros de programação e problemas comuns em sistemas operacionais. Escrito em C, o projeto permite que estudantes observem na prática o comportamento de códigos que geram erros como Memory Leak, Race Condition, Deadlock, entre outros.

## Status do Projeto
- **Estado atual**: Parcialmente funcional - 3 de 7 programas implementados (Memory Leak, Race Condition, Deadlock)
- **Última atualização**: 15 de setembro de 2025
- **Linguagem**: C
- **Compilador**: GCC com suporte a pthread

## Arquitetura do Projeto
```
projeto-emulador-erros-SO/
├── erros/                 # Códigos de demonstração de erros (.c)
│   ├── buffer_overflow.c  # [Não implementado ainda]
│   ├── core_dump.c       # [Não implementado ainda]
│   ├── deadlock.c        # ✅ Implementado e funcional
│   ├── memory_leak.c     # ✅ Implementado e funcional  
│   ├── race_condition.c  # ✅ Implementado e funcional
│   ├── segfault.c        # [Não implementado ainda]
│   └── stack_overflow.c  # [Não implementado ainda]
├── output/               # Executáveis compilados
│   ├── deadlock
│   ├── memory_leak
│   ├── race_condition
│   └── runner           # Menu interativo principal
├── runner/              # Sistema de menu e compilação
│   ├── runner.c        # Código do menu interativo
│   └── run.sh          # Script de compilação
├── docker/             # [Pasta vazia - Docker não usado no Replit]
└── README.md          # Documentação original do projeto
```

## Como Executar

### Método 1: Menu Interativo (Recomendado)
O projeto está configurado com um workflow que executa automaticamente o menu interativo. Basta clicar no console para interagir com o programa.

### Método 2: Compilação Manual
```bash
# Tornar o script executável
chmod +x runner/run.sh

# Compilar todos os programas
./runner/run.sh

# Executar o menu interativo
./output/runner
```

### Método 3: Executar programas individuais
```bash
./output/memory_leak      # Demonstra vazamento de memória
./output/race_condition   # Demonstra condições de corrida
./output/deadlock         # Demonstra deadlock entre threads
```

## Programas Implementados

### ✅ Memory Leak (Vazamento de Memória)
- Demonstra alocação dinâmica sem liberação
- Simula cadastro de usuários com buffers de 1MB cada
- Mostra o crescimento progressivo do uso de memória

### ✅ Race Condition (Condição de Corrida)  
- Demonstra threads acessando recurso compartilhado
- Mostra comportamento não determinístico
- Utiliza pthread para criar múltiplas threads

### ✅ Deadlock
- Demonstra bloqueio mútuo entre threads
- Threads tentam adquirir recursos simultaneamente
- Pode travar o programa intencionalmente

## Configuração do Ambiente Replit

### Workflow Configurado
- **Nome**: "Sistema de Demonstração de Erros"
- **Comando**: `./output/runner`
- **Tipo**: Console (aplicação de terminal)
- **Status**: Ativo e funcional

### Dependências
- **Compilador**: Clang 14 (já instalado)
- **Bibliotecas**: pthread (para threads), padrões C

## Mudanças Recentes
- **15/09/2025**: Projeto importado do GitHub e configurado para Replit
- **15/09/2025**: Compilação bem-sucedida de 3 programas implementados
- **15/09/2025**: Workflow de console configurado para execução interativa
- **15/09/2025**: Testes realizados - todos os programas funcionais

## Notas Importantes

### Programas Perigosos
⚠️ **Atenção**: Alguns programas podem afetar o sistema se executados por muito tempo:
- Memory Leak: Consome memória progressivamente
- Deadlock: Pode travar completamente
- Race Condition: Comportamento imprevisível

### Limitações Atuais
- 4 programas ainda não foram implementados (arquivos vazios)
- Alguns programas podem precisar ser interrompidos manualmente
- Docker não é usado no ambiente Replit

## Próximos Passos Sugeridos
1. Implementar os programas restantes (buffer_overflow, core_dump, segfault, stack_overflow)
2. Melhorar a interface do runner com cores e formatação
3. Adicionar opção de timeout automático para programas que podem travar
4. Implementar logs de execução para análise educacional