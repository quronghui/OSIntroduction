// 题目一: 通过信号量实现锁(  二值信号量 )

#include "semaphore_api.h"
#include <assert.h>
#include <stdio.h>

// 信号量的初始化
void Sem_init(sem_t *sem, int pshared, unsigned int value)
{
    int rc = sem_init(sem, pshared, value);
    assert(rc==0);
}

// sem_wait() 信号量的获取检测
void Sem_wait( sem_t *sem )
{
    int rc = sem_wait(sem);
    assert(rc == 0);
}

// sem_post() 信号量获取检测
void Sem_post(sem_t *sem)
{
    int rc = sem_post(sem);
    assert(rc == 0);
}

// // 临界区的使用
// void *mythread( void *arg )
// {
//     sem_t sem;
//     Sem_init(&sem, 0 , 1);

//     Sem_wait(&sem);
//     // code
//     Sem_post(&sem);

//     return NULL;
// }