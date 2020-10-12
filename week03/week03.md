# week03

进程=计算任务+I/O任务（资源任务）

操作文件的方案

- 基于文件的操作符的由os提供的底层方案 init fd creat read open write
- 基于文件流语言由库提供支持的 是对于文件描述符操作的封装 FILE *fp fopen fwrite fread...

vim编辑器命令

- 打开vim编辑器 新建或编辑该文件 vi xxx.xxx 
- 保存退出编辑器 
  - esc——>shift+：——> wq enter

Linux常用命令

- time ./执行文件名
- gcc -g -Wall xxx.c -o 执行文件名
- cat xxx.c
- cp
- clear

## 文件操作类函数

------

main函数参数解析

- int main（int argc, char *argv[]）;
- argc：参数计数
- argv：位置参数

open函数

fopen函数

fwrite函数参数解析

- size_t fwrite(const void * ptr, size_t size, size_t nmemb, FILE * stream);

- 返回值：返回实际写入的[数据块](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=8783783&ss_c=ssc.citiao.link)数目

  （1）ptr：是一个指针，对fwrite来说，是要获取数据的地址；

  （2）size：要写入内容的单字节数；

  （3）nmemb:要进行写入size字节的[数据项](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=452927&ss_c=ssc.citiao.link)的个数；

  （4）stream:目标文件指针；

fdopen函数

- FILE * fdopen(int fildes, const char * mode);
- 参数1：已经打开的文件描述符
- 参数2：文件流对该文件的操作说明 w r w+ r+
- 返回值：fp 用来操作文件描述符所指向的文件

