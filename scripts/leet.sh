#!/bin/bash

get_help(){
    echo "leet: command line tool to manage leetcode programs."
    echo -e "\t-get [no]: get the number of the question which is not solved."
    echo -e "\t-new [no]: create a new folder for the code not solved"
    echo -e "\t-glink no: get the link for question number"
}

if [ "$1" == "-get" ]; then
    if [ $# == 1 ]; then
        counter=1
    else
        counter=$2
    fi
    for i in {1..2000}; do
        if [ ! -d "$i" ]; then
            ((counter--))
            if [ "$counter" -le 0 ]; then
                echo "$i"
                break
            fi
        fi
    done
elif [ "$1" == "-new" ]; then
    if [ $# == 1 ]; then
        for i in {1..2000}; do
            if [ ! -d "$i" ]; then
                file="$i"
                break
            fi
        done
    else
        file="$2"
    fi
    mkdir "$file" && cd "$file" || exit
    touch "1.cpp"
    FILE="../lists.md"
    LINK=$(grep -e "\[$file\." "$FILE" | grep -o -e "http[^)]*")
    echo "// $LINK" > "1.cpp"
elif [ "$1" == "-glink" ]; then
    if [ $# == 2 ]; then
        FILE="./lists.md"
        LINK=$(grep -e "\[$2\." "$FILE" | grep -o -e "http[^)]*")
        echo "$LINK"
    else 
        get_help
    fi
else
    get_help
fi
