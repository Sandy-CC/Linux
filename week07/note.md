# Week07
ps -ef 查看进程

kill 进程号 停止进程

echo $HOME 查看根目录

echo $PWD 查看当前工作目录

env 查看环境变量

gcc -Wall -fpic -shared dlib.c -o libdlib.so 生成简单动态共享链接库

gcc -Wall test.c -o test -L ./ -ldlib 链接动态库生成可执行文件

-Wall 显示所有警告

