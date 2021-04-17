#!/bin/bash
#编译和生成静态库
make
ar -crv liblist.a list.o
