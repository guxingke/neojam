# 源码阅读笔记

主要是源码分析的一些零散记录


## C 语言

### 宏

本质是编译阶段的一次预处理，逻辑比较简单，纯文本替换，碰到难以理解的宏代码，可使用下方命令进行宏展开。

```bash
gcc -E src/symbol.c 
```

得到预处理之后的代码。

### static 关键字

static 关键字的出现位置有不同的作用。

- 全局变量变局部变量。  
比如 src/dll.c 的 verbose 变量。
```c
static int verbose;
```

表明该变量为当前文件所有。

- 全局方法变局部方法。
比如 src/thread.c 的 shell 方法。
```c
static void *shell(void *args) {
...
}
```

表明方法为当前文件所有。

- 修饰方法内变量。
比如 src/class.c 的 linkClass 方法内部 obj_fnlzr_mthd 变量。
```c
void linkClass(Class *class) {
    static MethodBlock *obj_fnlzr_mthd = NULL;
...
}
```
这个操作等同于全局变量，但是只限于在该方法内访问。

