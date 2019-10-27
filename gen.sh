#!/bin/sh

if [ "$#" -gt "0" ]; then
    CHAPTER=$(printf "%02d" "$1")
    if [ ! -d "Chapter$CHAPTER" ]; then
        mkdir "Chapter$CHAPTER"
    fi
    if [ "$#" -gt "1" ]; then
        EX=$(printf "%02d" "$2")
        cd "Chapter$CHAPTER"
        if [ ! -d "$CHAPTER.$EX" ]; then
            mkdir "$CHAPTER.$EX"
        fi
        cd "$CHAPTER.$EX"
        touch "main.cpp"
        cat ../../main_cpp_template >> main.cpp
    fi
fi
