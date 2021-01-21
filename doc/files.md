# 源码文件说明

## src 目录

c 源码目录，共计约 2w 行代码。

```properties
src                                         - 源码目录
├── access.c                                - 访问权限相关
├── alloc.c                                 - 内存分配
├── alloc.h
├── annotations.c                           - 注解
├── annotations.h
├── arch.h                                  - cpu 架构， 当前 amd64
├── cast.c                                  - 类型转换， 类型校验
├── class.c                                 - class 文件，以及内存表示
├── class.h
├── classlib.h                              - classpath, 当前 gnu classpath
├── config.h                                - 一些宏配置
├── darwin_x86_64                           - 操作系统+架构
│         ├── darwin_callNative.S           - 汇编实现的函数调用
│         ├── darwin_dll_md.c               - 动态库
│         ├── darwin_init.c                 - 操作系统初始化
│         └── darwin_os.c                   - 操作系统特有支持
├── dll.c                                   - 动态库
├── excep.c                                 - 异常相关
├── excep.h
├── execute.c                               - 执行器
├── frame.c                                 - 栈帧
├── frame.h
├── gcp                                     - gnu classpath, 内部是一些特殊或额外实现
│         ├── gcp.h                         
│         ├── gcp_alloc.c                   
│         ├── gcp_class.c
│         ├── gcp_dll.c
│         ├── gcp_excep.c
│         ├── gcp_frame.c
│         ├── gcp_jni.c
│         ├── gcp_natives.c
│         ├── gcp_properties.c
│         ├── gcp_reflect.c
│         └── gcp_thread.c
├── hash.c                                  - hash 表实现
├── hash.h
├── hooks.c                                 - 内部钩子
├── init.c                                  - 虚拟机初始化
├── inlining.h                              
├── interp-indirect.h                       
├── interp.c                                - 核心解释器
├── interp.h
├── jam.h                                   - 核心头文件
├── jni-internal.h
├── jni-stubs.c
├── jni.c                                   - JNI 实现
├── jni.h
├── lock.c                                  - pthread lock, monitor 
├── lock.h
├── main.c                                  - 启动入口
├── natives.c                               - 本地方法
├── natives.h
├── properties.c                            - 属性
├── properties.h
├── reflect.c                               - 反射
├── reflect.h
├── resolve.c                               - 解析器
├── shutdown.c                              - 虚拟机关闭
├── sig.c                                   - 方法签名
├── sig.h
├── string.c                                - 字符串
├── stubs.c                                 - 桩
├── stubs.h
├── symbol.c                                - 内部符号
├── symbol.h
├── thread.c                                - 线程实现， pthread
├── thread.h
├── time.c                                  - 时间工具
├── utf8.c                                  - uft8 工具, 内部有个字符串池
├── zip.c                                   - zip 支持, libz
└── zip.h

2 directories, 69 files

```

### main.c

启动入口

1. 解析参数
2. 初始化虚拟机
3. 加载主类
4. 准备应用参数
5. 调用主类 main 方法
6. 处理虚拟机退出

### init.c

初始化, 主要协调虚拟机内部的组件的初始化顺序。

1. 生成虚拟机的默认参数
2. 初始化虚拟机
   1. hooks
   2. properties
   3. alloc
   4. thead stage 1
   5. uft8
   6. symbol
   7. class stage 1
   8. dll
   9. monitor
   10. string
   11. exception
   12. natives
   13. access
   14. frame
   15. jni
   16. interpreter
   17. class stage 2
   18. thread stage 2
   19. gc

## lib 目录

lib 目录是 jamvm 为了方便实现复写了一部分 gnu classpath 的一部分 java 代码。

jamvm 在类加载时，启动类加载器会优先加载 lib 编译的 class 文件，

## 其他