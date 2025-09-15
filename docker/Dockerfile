# Usando Ubuntu como base
FROM ubuntu:22.04

# Evita perguntas interativas durante a instalação
ENV DEBIAN_FRONTEND=noninteractive

# Atualiza e instala gcc e dependências
RUN apt-get update && \
    apt-get install -y gcc build-essential make git && \
    rm -rf /var/lib/apt/lists/*

# Cria pasta do projeto dentro do container
WORKDIR /app

# Copia todo o repositório para dentro do container
COPY . .

# Dá permissão para run.sh
RUN chmod +x runner/run.sh

# Compila todos os erros e o runner
RUN ./runner/run.sh

# Define entrypoint para rodar o runner
ENTRYPOINT ["./docker/entrypoint.sh"]