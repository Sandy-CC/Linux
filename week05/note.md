# Week05
文件操作：

- 系统I/O操作（无缓冲，基于文件描述符）——是由OS提供 更底层
- 标准I/O操作（带缓冲，基于文件流）——是对系统I/O的封装



- 单缓冲
- 双缓冲
- 环形缓冲池

三种类型：

- 系统缓冲区大小为1个字节——无缓冲
- 系统缓冲区的结束以 回车换行符 为标志 0至1024字节——行缓冲
- 以系统缓冲区默认大小为标志 1024字节

当遇到缓冲区的溢出（满）为条件时，子系统执行一次I/O操作