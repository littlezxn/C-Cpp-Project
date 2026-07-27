#!/bin/bash
if [ "$EUID" -ne 0 ]; then
    echo -e "\033[0;32mSuccess: The script is NOT running with sudo privileges.\033[0m"
    echo "Current directory:"
    pwd
    ls
    read -p "Enter your choice (c/c++), "x" for exit: " choice
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
    elif [ "$choice" == "x" ]; then
        echo "Exiting the script."
        exit 0
    else
        echo "Invalid choice"
    fi
else
    echo -e "\033[0;31mError: This script cannot be run with sudo!\033[0m" >&2
    exit 1
fi

