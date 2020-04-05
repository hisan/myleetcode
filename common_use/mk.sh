#!/bin/bash
#编译和生成静态库的脚本
make
ar -crv liblist.a list.o
