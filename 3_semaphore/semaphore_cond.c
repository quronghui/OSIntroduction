// 题目二: 信号量作为条件变量
/* 
*   - 父进程调用sem_wait(), 将sem值减一, sem<0 进入睡眠模式
*   - 子进程调用sem_post(), 将sem值加一, sem=0, 唤醒父进程
*/
#include "semaphore_api.h"
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

// 定义信号量
sem_t   sem;

// 子线程的函数
void *child(void *arg)
{
    printf("child  begin:   \n");
    Sem_post(&sem);
    return NULL;
}

int main( int argc, char *argv[] )
{
    Sem_init(&sem, 0, 0);
    printf("parent begin:   \n");

    pthread_t p;
    int  rc = pthread_create(&p, NULL, child, NULL);    assert(rc == 0);
    Sem_wait(&sem);     // wait child 

    printf("parent end.\n");
}