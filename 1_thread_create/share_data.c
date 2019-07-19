// 题目二: 进程的穿件后, 共享数据

#include  <stdio.h>
#include <assert.h>
#include <pthread.h>

// static一个用途是函数内部静态变量，只会被初始化一次，而且变量存储在全局数据段中而不是函数栈中
// volatile这变量很可能会被意想不到地改变，因此需要小心对待。优化器在用到这个变量时必须每次重新从虚拟内存中读取这个变量的值，而不是使用保存在寄存器里的备份。
static volatile int counter = 0;    

void *mythread(void *arg)       //void *(*start_routine) (void *) :  指针函数 指向void 类型, 后面是其形参
{
    printf( "%s begin \n", (char *)arg);     // 使用强制转换类型

    for( int i = 0; i<1e7; i++)
        counter = counter +1;           //  将counter 更新10^7次
    printf("%s: done\n", (char*) arg);
    return NULL;
}

// 
int main( int argc,  char *argv[] )
{
    pthread_t p1, p2;
    int rc;

    printf("main: begin\n");
    rc = pthread_create(&p1, NULL, mythread, "A");      // It returns from start_routine(). 返回值是指针函数的返回值, NULL; 第二个参数为空
    assert(rc == 0);    
    rc = pthread_create( &p2, NULL, mythread, "B");
    assert(rc==0);

    // join waits for threads to finish
    rc = pthread_join(p1, NULL);    assert(rc == 0);
    rc = pthread_join(p2, NULL);    assert(rc == 0);
    printf("main: done with both counter = %d. \n", counter);
    return 0;
}