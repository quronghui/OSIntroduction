// 题目二:  条件变量的创建和使用

#include "mutex_api.h"

//  Pthread_cond_wait使得线程进入等待模式
void Pthread_cond_wait(pthread_cond_t *cond,  pthread_mutex_t *mutex)
{
    int rc = pthread_cond_wait(cond, mutex);
    assert(rc==0);
}

//Pthread_cond_signal 唤醒线程
void  Pthread_cond_signal(pthread_cond_t *cond)
{
    int rc = pthread_cond_signal(cond);
    assert(rc == 0);
    
}

// int ready = 0;
// // 条件变量的初始化
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// // 临界区wait使得线程进入等待模式

// void wait(void *arg){

//     Pthread_mutex_lock(&lock);
//     while( ready == 0 )
//         Pthread_cond_wait(&cond, &lock);        // 让线程进入睡眠模式
//     Pthread_mutex_unlock(&lock);
// }

// // 临界区siginal: 唤醒等待的线程
// void signal(void *arg)
// {
//     Pthread_mutex_lock(&lock);
//     ready = 1;
//     Pthread_cond_signal(&cond);
//     Pthread_mutex_unlock(&lock);
// }
