## 1. 文件基本属性

使用`ls -l` 命令查看文件

![image-20200928120312768](images\image-20200928120312768.png)

- 显示内容的具体含义

![image-20200928120336759](images\image-20200928120336759.png)

## 2. 文件的存放

> 文件

```
文件名，大小，链接数，权限，时间，地址表
```

地址表单独存放，使用指针指向地址表

基本目录只有文件名和索引

----

文件系统解决问题

- 由字符路径转变为 inode 节点号，再转变为物理地址。  i-node 节点可以离散放置
- 目录（文件）：解决从路径中取关键字检索 inod

由 index-node（索引节点）完成以下功能：

（1）完全，权限控制

（2）通过地址表访问控制块

------

## 3. 测试命令

#### （1）测试脚本命令

```bash
[root@iZkxb2rx1u09i3Z week2]# vim test1.sh
--------------------------------
echo 'hello shell'
cal
time
--------------------------------
[root@iZkxb2rx1u09i3Z week2]# ls
test1.sh
[root@iZkxb2rx1u09i3Z week2]# ./test1.sh
-bash: ./test1.sh: Permission denied
[root@iZkxb2rx1u09i3Z week2]# ls -l test1.sh 
-rw-r--r-- 1 root root 28 Sep 28 08:33 test1.sh
[root@iZkxb2rx1u09i3Z week2]# chmod 777 test1.sh 
[root@iZkxb2rx1u09i3Z week2]# ./test1.sh 
hello shell
   September 2020   
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30


real	0m0.000s
user	0m0.000s
sys	0m0.000s
[root@iZkxb2rx1u09i3Z week2]# 
```

----

```
man strace
```

----

#### （2）测试 strace 命令

将 Return 0 删除，最终结果返回的是9，就是 writer 的返回值

```bash
[root@iZkxb2rx1u09i3Z week2]# vim test2.c
[root@iZkxb2rx1u09i3Z week2]# gcc test2.c
[root@iZkxb2rx1u09i3Z week2]# starce ./a.out
-bash: starce: command not found
[root@iZkxb2rx1u09i3Z week2]# strace ./a.out
execve("./a.out", ["./a.out"], [/* 25 vars */]) = 0
brk(0)                                  = 0x87b000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f82eb95d000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=40238, ...}) = 0
mmap(NULL, 40238, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f82eb953000
close(3)                                = 0
open("/lib64/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0`&\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=2156240, ...}) = 0
mmap(NULL, 3985920, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f82eb36f000
mprotect(0x7f82eb532000, 2097152, PROT_NONE) = 0
mmap(0x7f82eb732000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1c3000) = 0x7f82eb732000
mmap(0x7f82eb738000, 16896, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f82eb738000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f82eb952000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f82eb950000
arch_prctl(ARCH_SET_FS, 0x7f82eb950740) = 0
mprotect(0x7f82eb732000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7f82eb95e000, 4096, PROT_READ) = 0
munmap(0x7f82eb953000, 40238)           = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f82eb95c000
write(1, "0=hello\n", 80=hello
)                = 8
write(1, "1=hello\n", 81=hello
)                = 8
write(1, "2=hello\n", 82=hello
)                = 8
write(1, "3=hello\n", 83=hello
)                = 8
write(1, "4=hello\n", 84=hello
)                = 8
write(1, "5=hello\n", 85=hello
)                = 8
write(1, "6=hello\n", 86=hello
)                = 8
write(1, "7=hello\n", 87=hello
)                = 8
write(1, "8=hello\n", 88=hello
)                = 8
write(1, "9=hello\n", 89=hello
)                = 8
write(1, "10=hello\n", 910=hello
				 = 9
)
.......省略
write(1, "98=hello\n", 998=hello
)               = 9
write(1, "99=hello\n", 999=hello
)               = 9
exit_group(9)                           = ?
+++ exited with 9 +++
[root@iZkxb2rx1u09i3Z week2]# 

```

