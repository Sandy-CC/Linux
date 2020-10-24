# week03

#### 进程=计算任务+I/O任务（资源任务）

#### 操作文件的方案

- 基于文件的操作符的由os提供的底层方案 init fd creat read open write
- 基于文件流语言由库提供支持的 是对于文件描述符操作的封装 FILE *fp fopen fwrite fread...

#### vim编辑器命令

- 打开vim编辑器 新建或编辑该文件 vi xxx.xxx 
- 保存退出编辑器 
  - esc——>shift+：——> wq enter

![image-20201012182111305](C:\Users\running\AppData\Roaming\Typora\typora-user-images\image-20201012182111305.png)

![image-20201012205230573](C:\Users\running\AppData\Roaming\Typora\typora-user-images\image-20201012205230573.png)

![image-20201012205407529](C:\Users\running\AppData\Roaming\Typora\typora-user-images\image-20201012205407529.png)



Linux常用命令

- time ./执行文件名
- gcc -g -Wall xxx.c -o 执行文件名
- cat xxx.c
- cp
- clear

## 文件操作类函数

------

#### main函数参数解析

- int main（int argc, char *argv[]）;
- argc：参数计数
- argv：位置参数

------

#### open函数

```
链接：https://blog.csdn.net/small_qch/article/details/10442241?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.add_param_isCf&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.add_param_isCf
```

​		头文件

```
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
```

**函数原型：**

```
int open( const char * pathname, int flags);

int open( const char * pathname,int flags, mode_t mode);
```

**作用：**以各种方式打开文件

**返回值：**返回打开的文件句柄，-1 打开失败

**函数说明**： 参数pathname 指向欲打开的文件路径字符串`，`既可以是相对路径也可以是绝对路径。`flags`参数有一系列常数值可供选择，可以同时选择多个常数用按位或运算符连接起来，所以这些常数的宏定义都以`O_`开头，表示or

下列是参数flags 所能使用的旗标:
- 必选项：以下三个常数中必须指定一个，且仅允许指定一个。**

  ```
  O_RDONLY 以只读方式打开文件
  O_WRONLY 以只写方式打开文件
  O_RDWR 以可读写方式打开文件。上述三种旗标是互斥的，也就是不可同时使用，但可与下列的旗标利用OR(|)运算符组合。
  ```

- 以下可选项可以同时指定0个或多个，和必选项按位或起来作为flags参数。

  ```
  O_CREAT 若欲打开的文件不存在则自动建立该文件。
  O_EXCL 如果O_CREAT 也被设置，此指令会去检查文件是否存在。文件若不存在则建立该文件，否则将导致打开文件错误。此外，若O_CREAT与O_EXCL同时设置，并且欲打开的文件为符号连接，则会打开文件失败。
  O_NOCTTY 如果欲打开的文件为终端机设备时，则不会将该终端机当成进程控制终端机。
  O_TRUNC 若文件存在并且以可写的方式打开时，此旗标会令文件长度清为0，而原来存于该文件的资料也会消失。
  O_APPEND 当读写文件时会从文件尾开始移动，也就是所写入的数据会以附加的方式加入到文件后面。
  O_NONBLOCK 以不可阻断的方式打开文件，也就是无论有无数据读取或等待，都会立即返回进程之中。
  O_NDELAY 同O_NONBLOCK。
  O_SYNC 以同步的方式打开文件。
  O_NOFOLLOW 如果参数pathname 所指的文件为一符号连接，则会令打开文件失败。
  O_DIRECTORY 如果参数pathname 所指的文件并非为一目录，则会令打开文件失败。
  ```

  

第三个参数`mode`指定文件权限，可以用八进制数表示，比如0644表示`-rw-r--r--`，也可以用`S_IRUSR`、`S_IWUSR`等宏定义按位或起来表示，参数mode 则有下列数种组合，只有在建立新文件时才会生效，文件权限由`open`的`mode`参数和当前进程的`umask`掩码共同决定，因此该文件权限应该为（mode-umaks）。

```
S_IRWXU 00700 权限，代表该文件所有者具有可读、可写及可执行的权限。
S_IRUSR 或S_IREAD，00400权限，代表该文件所有者具有可读取的权限。
S_IWUSR 或S_IWRITE，00200 权限，代表该文件所有者具有可写入的权限。
S_IXUSR 或S_IEXEC，00100 权限，代表该文件所有者具有可执行的权限。
S_IRWXG 00070权限，代表该文件用户组具有可读、可写及可执行的权限。
S_IRGRP 00040 权限，代表该文件用户组具有可读的权限。
S_IWGRP 00020权限，代表该文件用户组具有可写入的权限。
S_IXGRP 00010 权限，代表该文件用户组具有可执行的权限。
S_IRWXO 00007权限，代表其他用户具有可读、可写及可执行的权限。
S_IROTH 00004 权限，代表其他用户具有可读的权限
S_IWOTH 00002权限，代表其他用户具有可写入的权限。
S_IXOTH 00001 权限，代表其他用户具有可执行的权限。
```

------

#### fopen函数

- FILE *fopen(char *filename, char *mode);
- `filename`为文件名（包括文件路径）
- `mode`为打开方式

实例：

```
#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
    FILE *fp;
    char str[N + 1];
    //判断文件是否打开失败
    if ( (fp = fopen("d:\\demo.txt", "rt")) == NULL ) {
        puts("Fail to open file!");
        exit(0);
    }
    //循环读取文件的每一行数据
    while( fgets(str, N, fp) != NULL ) {
        printf("%s", str);
    }
   
    //操作结束后关闭文件
    fclose(fp);
    return 0;
}
```

fopen() 函数的打开方式

- r(read)：读
- w(write)：写
- a(append)：追加
- t(text)：文本文件
- b(banary)：二进制文件
- +：读和写

![image-20201012205914170](C:\Users\running\AppData\Roaming\Typora\typora-user-images\image-20201012205914170.png)



------

#### fwrite函数参数解析

- size_t fwrite(const void * ptr, size_t size, size_t nmemb, FILE * stream);

- 返回值：返回实际写入的[数据块](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=8783783&ss_c=ssc.citiao.link)数目

  （1）ptr：是一个指针，对fwrite来说，是要获取数据的地址；

  （2）size：要写入内容的单字节数；

  （3）nmemb:要进行写入size字节的[数据项](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=452927&ss_c=ssc.citiao.link)的个数；

  （4）stream:目标文件指针；

------

#### fdopen函数

- FILE * fdopen(int fildes, const char * mode);
- 参数1：已经打开的文件描述符
- 参数2：文件流对该文件的操作说明 w r w+ r+
- 返回值：fp 用来操作文件描述符所指向的文件

