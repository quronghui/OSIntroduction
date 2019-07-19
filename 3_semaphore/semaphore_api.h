//  信号量的函数接口
#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <semaphore.h>

// 信号量的初始化
void Sem_init(sem_t *sem, int pshared, unsigned int value);


// 信号量的操作函数
void Sem_post(sem_t *sem);
void Sem_wait( sem_t *sem );


#endif