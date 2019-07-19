//  题目一: 线程的创建.  执行顺序: 由调度程序决定那个线程先执行;

#include  <stdio.h>
#include <assert.h>
#include <pthread.h>

void *mythread(void *arg)       //void *(*start_routine) (void *) :  指针函数 指向void 类型, 后面是其形参
{
    printf( " %s \n", (char *)arg);     // 使用强制转换类型
    return NULL;
}

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
    printf("main: end\n");
    return 0;
}