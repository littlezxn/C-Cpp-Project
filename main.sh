#!/bin/bash
echo "Current directory:"
pwd
ls
read -p "Enter your choice (c/c++): " choice
if [ "$choice" == "c" ]; then
    cd "C"
    ls -l
elif [ "$choice" == "c++" ]; then
    cd "Cpp"
    ls -l
elif [ "$choice" == "main.c" ]; then
    cat main.c
elif [ "$choice" == "main.sh" ]; then
    cat main.sh
else
    echo "Invalid choice"
fi
