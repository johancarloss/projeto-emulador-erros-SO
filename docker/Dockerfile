# Dockerfile
FROM ubuntu:22.04

# Instalar dependências necessárias
RUN apt-get update && \
    apt-get install -y gcc build-essential make bash && \
    apt-get clean

# Criar diretório de trabalho
WORKDIR /app

# Copiar todo o projeto para dentro do container
COPY . .

# Dar permissão para o run.sh
RUN chmod +x runner/run.sh

# Definir entrypoint
ENTRYPOINT ["./runner/run.sh"]