// 锁的接口
#ifndef MUTEX_API_H
#define MUTEX_API_H

#include <pthread.h>
#include <assert.h>
#include <stdio.h>
// 锁的初始化
extern void Pthread_mutex_init(pthread_mutex_t *mutex);     

// 锁的获取和释放
extern void Pthread_mutex_lock( pthread_mutex_t *mutex );
extern void Pthread_mutex_unlock( pthread_mutex_t *mutex );


#endif