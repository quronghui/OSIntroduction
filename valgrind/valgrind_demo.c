// valgrind 内存泄漏的查找方式

//gcc -Wall -g valgrind_demo.c -o valgrind_demo
//  执行条件 : valgrind --tool=memcheck --leak-check=full ./valgrind_demo
// 将错误写进日志: valgrind --tool=memcheck --leak-check=full --log-file=mem_leak.log ./valgrind_demo
// 和gdb一起调试: valgrind --tool=memcheck --leak-check=full --log-file=mem_leak.log gdb valgrind_demo

#include <stdlib.h>
 #include <stdio.h>

 //问题1:内存越界
//问题2:内存泄露. 没有进行释放
void f(void){
    int* x = malloc(10 * sizeof(int));
    x[10] = 0; 
}
 
int main(int argc, char* argv[]){
    f();
    return 0;
}