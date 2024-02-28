#include <stdlib.h>  // lib，包含了malloc和free函数
#include <stdio.h>   // io是输出相关

 
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

int main (){
 
    int var = 20; /* 实际变量的声明 */
 
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

    //----1. *的第一个作用，声明指针变量
    int *ip; /* 这里*是取值符，ip就是地址 */
 
    ip = &var; /*  &为取地址符 */
 

    /*----2. *的第二个作用，取出地址中的值 */
    printf("Value of *ip variable: %d\n", *ip );


    //接着哟个动态数组说下*的其他作用
    int* array;
    int n, i;
    n = 5;
    //----3、*的第三个作用动态分配内存
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


    //----4、*的第四个作用，通过引用传参
    int value = 10;
    updateValue(&value);
    printf("After: %d\n", value);

 
    return 0;
 
}