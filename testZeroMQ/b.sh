#!/bin/bash

url="http://localhost:8080/api"

for i in {1..1000}; do
    data="{\"task_number\": $i}"
    echo "Sending request $i: $data"
    curl -X POST -H "Content-Type: application/json" -d "$data" -o /dev/null -s "$url" &
done

# Ожидание завершения всех фоновых процессов
