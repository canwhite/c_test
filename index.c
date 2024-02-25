#include <stdio.h>
 
/** 
 * 这里编译用的clang是xcode的，位置在/usr/bin/clang
 * 当然也可以直接使用llvm的，它的安装位置在
 * /opt/homebrew/opt/llvm/bin/clang 
 * 注意无论clang还是gcc，都是编译器，c是直接编译成机器码，不需要解释
 * 这也是它为什么快的原因
 */

int main (){
 
    int var = 20; /* 实际变量的声明 */
 
    int *ip; /* 这里*是取值符，ip就是地址 */
 
    ip = &var; /*  &为取地址符 */
 
    /* 输出var的地址 */
    printf("Address of var variable: %p\n", &var );
 
    /* 输出指针变量中存储的地址 */
    printf("Address stored in ip variable: %p\n", ip );
 
    /* 使用指针访问值 即用*取出地址中的值 */
    printf("Value of *ip variable: %d\n", *ip );
 
    return 0;
 
}