#!/bin/bash

g++ -Wall -fexceptions -std=c++11 -g  -c ../test/linkedlist.cpp -o ../obj/linkedlist.o
g++  -o ../bin/linkedlist ../obj/linkedlist.o
./../bin/linkedlist