#include <stdlib.h>  // lib，包含了malloc和free函数
#include <stdio.h>   // io是输出相关
#include <pthread.h>
 
/** 
 * 这里编译用的clang是xcode的，位置在/usr/bin/clang
 * 当然也可以直接使用llvm的，它的安装位置在
 * /opt/homebrew/opt/llvm/bin/clang 
 * 注意无论clang还是gcc，都是编译器，c是直接编译成机器码，不需要解释
 * 这也是它为什么快的原因
 */

void updateValue(int *pValue){
    *pValue = 20;
}

//Object
typedef struct  
{
    int id;
    char name[50];
}  Object;

//async-sync
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 初始化互斥锁
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // 初始化条件变量
int done = 0; // 定义一个全局变量

void* async_func(void* arg){

    printf("async init \n");
    //----------上互斥锁-----------
    pthread_mutex_lock(&mutex);

    //上锁和解锁是为了保持在中间这个值被锁定
    done = 1;
    pthread_cond_signal(&cond); //发送信号，异步操作已完成
    
    //----------解锁互斥锁----------
    pthread_mutex_unlock(&mutex);
    
    //最后返回值
    return (void*)1;
}


int main (){
 
    // c语言基本数据类型
    int num = 10;
    char ch = 'a';
    float f = 3.14f;
    double d = 3.14;
    printf("The int variable is: %d\n", num);     // 输出整型变量
    printf("The char variable is: %c\n", ch);     // 输出字符型变量
    printf("The float variable is: %.2f\n", f);   // 输出单精度浮点型变量，保留2位小数
    printf("The double variable is: %.2lf\n", d); // 输出双精度浮点型变量，保留2位小数 

    //基本数组 type array[size]
    int numbers[5] = {1, 2, 3, 4, 5};

    //----1. *声明指针变量

    int var = 20; /* 实际变量的声明 */
    
    int *ip; /* 这里*是取值符，ip就是地址 */
 
    ip = &var; /*  &为取地址符 */
 

    /*----2. *取出地址中的值 */
    printf("Value of *ip variable: %d\n", *ip );


    //接着哟个动态数组说下*的其他作用
    int* array;
    int n, i;
    n = 5;
    //----3、*动态分配内存
    array = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        array[i] = i;
    }
    // 打印数组中的元素
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    // 释放内存
    free(array);
    printf("\n");

    //----4、*通过引用传参
    int value = 10;
    updateValue(&value);
    printf("After: %d\n", value);


    //动态的对象数组
    Object* objects = (Object *)malloc(10 * sizeof(Object));
    if(objects == NULL){
        printf("内存不足，无法分配内存。\n");
        //1是通用错误码
        return 1;
    }
    //可以通过索引访问，像普通数组一样
    for (int i = 0; i < 10; i++)
    {
        //c中.和->的区别
        objects[i].id = i;
        sprintf(objects[i].name, "对象 %d", i);
        printf("%s 的 id 是 %d\n", objects[i].name, objects[i].id);
    }
    free(objects);

    //async
    pthread_t thread;
    //创建一个新线程来执行异步任务
    pthread_create(&thread, NULL, async_func, NULL); 
    //上锁互斥锁
    pthread_mutex_lock(&mutex);
    while (done == 0) {
        // 如果异步函数还没设置 "done" 为1, 则等待
        pthread_cond_wait(&cond, &mutex); 
    }
    // 解锁互斥锁
    pthread_mutex_unlock(&mutex); 
    // 这里，异步操作已经转换为同步
    printf("Now the async task is done and onwards!\n"); // 打印消息表示异步任务已完成

 
    return 0;
 
}