#!/bin/bash

# Cria a pasta output se não existir
mkdir -p output

echo "=============================="
echo " Iniciando compilação do projeto"
echo "=============================="

# Compila todos os arquivos .c da pasta erros
for arquivo in erros/*.c; do
    nome_saida=$(basename "$arquivo" .c)  # retira extensão
    echo "Compilando $arquivo..."
    gcc "$arquivo" -o "output/$nome_saida" -pthread

    if [ $? -ne 0 ]; then
        echo "Erro ao compilar $arquivo"
    else
        echo "$arquivo compilado com sucesso."
    fi
    echo "------------------------------"
done

# Compila o runner
echo "Compilando runner/runner.c..."
gcc runner/runner.c -o output/runner -pthread
if [ $? -ne 0 ]; then
    echo "Erro ao compilar runner.c"
else
    echo "runner.c compilado com sucesso."
fi

echo "=============================="
echo "Compilação finalizada!"
echo "=============================="