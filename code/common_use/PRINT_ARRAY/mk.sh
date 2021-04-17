#!/bin/bash
#编译和生成静态库

rm ./*.a

make clean && make
ar -cvr libprint_array.a print_array.o
