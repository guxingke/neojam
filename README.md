# NeoJam

[JamVM](http://jamvm.sourceforge.net/) 的 macOS x86_64 精简移植版。

配合 [GNU Classpath](https://www.gnu.org/software/classpath/) 作个人研究之用。


# 编译

前置条件, 安装 `Xcode` 或者 `Command Line Tools`。

## 编译安装 GNU Classpath

参考 [classpath-0.99](https://github.com/guxingke/classpath-0.99) 编译安装

## 编译 NeoJam 

### 编译 classes

```bash
cd lib && ./build.sh && cd ../
```

### 编译 NeoJam

- 编译

```bash
mkdir build
cd build
cmake ../
make
```

- 测试

```bash
cat <<EOF > HelloWorld.java
public class HelloWorld {
  public static void main(String[] args) {
    String x = "Hello";
    String y = " NeoJam";

    System.out.println(x + y);
  }
}
EOF

javac HelloWorld.java

./java HelloWorld

# 输出 `Hello NeoJam` 即为正常
```

# 调试

使用 Clion 打开即可。

# 局限

1. 只支持 macos x86_64，需要调试其他平台，可参考原项目进行移植。


# 源码分析相关

- [源码文件说明](doc/files.md)
