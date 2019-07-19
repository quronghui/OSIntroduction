// 条件变量的接口
#ifndef COND_API_H
#define COND_API_H

#include <pthread.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

// 条件变量的睡眠和唤醒
extern void Pthread_cond_wait(pthread_cond_t *cond,  pthread_mutex_t *mutex);
extern void  Pthread_cond_signal(pthread_cond_t *cond);


#endif