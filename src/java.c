#include <string.h>
#include "core/jni.h"
//jni.h文件包含在 C 代码中所需要的 JNI 的所有类型和函数定义

//1.包括准备本机应用程序以处理 Java 代码
//2.将 JVM 嵌入本机应用程序
//3.然后从该应用程序内找到并调用 Java 方法。
int main() {
/*
接下来，声明所有希望在程序中使用的变量。
JavaVMOption options[] 具有用于 JVM 的各种选项设置。
当声明变量时，确保所声明的JavaVMOption options[] 数组足够大，以便能容纳您希望使用的所有选项。
在本例中，我们使用的唯一选项就是类路径选项。
因为在本示例中，我们所有的文件都在同一目录中，所以将类路径设置成当前目录。
可以设置类路径，使它指向任何您希望使用的目录结构。*/
    JavaVMOption options[1];
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args;
/*JNIEnv *env          表示 JNI 执行环境。
JavaVM jvm             是指向 JVM 的指针,我们主要使用这个指针来创建、初始化和销毁 JVM。
JavaVMInitArgs vm_args 表示可以用来初始化 JVM 的各种 JVM 参数。*/

    long status;
    jclass cls;
    jmethodID mid;
    jint square;
    jboolean not;
/*avaVMInitArgs 结构表示用于 JVM 的初始化参数。
在执行 Java 代码之前，可以使用这些参数来定制运行时环境。
正如您所见，这些选项是一个参数,而 Java 版本是另一个参数。
按如下所示设置了这些参数：*/

/*为 JVM 设置类路径，以使它能找到所需要的 Java 类。
在这个特定示例中，因为 Sample2.class 和Sample2.exe 都位于同一目录中，所以将类路径设置成当前目录。
我们用来为 Sample2.c 设置类路径的代码如下所示：*/
    options[0].optionString = "-Djava.class.path=.";
    memset(&vm_args, 0, sizeof(vm_args));
    vm_args.version = JNI_VERSION_1_2;
    vm_args.nOptions = 1;
    vm_args.options = options;

/*创建 JVM
处理完所有设置之后，现在就准备创建 JVM 了。先从调用方法开始
如果成功，则这个方法返回零，否则，如果无法创建 JVM，则返回JNI_ERR。*/
    status = JNI_CreateJavaVM(&jvm, (void **) &env, &vm_args);

    if (status != JNI_ERR) {
/*
查找并装入 Java 类
一旦创建了 JVM 之后，就可以准备开始在本机应用程序中运行 Java 代码。
首先，需要使用FindClass() 函数查找并装入 Java 类，如下所示：
cls 变量存储执行FindClass() 函数后的结果,如果找到该类，则 cls 变量表示该Java 类的句柄,
如果不能找到该类，则 cls 将为零。
*/
        cls = (*env)->FindClass(env, "HelloWorld");
//        printf("test1,cls=%d...\n", cls);

        if (cls != 0) {
/*
查找 Java 方法
接下来，我们希望用 GetStaticMethodID() 函数在该类中查找某个方法。
我们希望查找方法 intMethod，它接收一个 int 参数并返回一个 int。
以下是查找 intMethod 的代码：
*/
            mid = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");
/*
mid 变量存储执行 GetStaticMethodID() 函数后的结果。
如果找到了该方法，则 mid 变量表示该方法的句柄。
如果不能找到该方法，则mid 将为零。
*/
            if (mid != 0) {
                (*env)->CallStaticVoidMethod(env, cls, mid);
//                printf("Result of voidMethod");
            }
        }

        (*jvm)->DestroyJavaVM(jvm);
        return 0;
    } else
        return -1;
}

