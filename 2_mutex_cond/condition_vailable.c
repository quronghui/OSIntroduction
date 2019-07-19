// 题目五: 条件变量的定义和程序编写

// 问题一:  done 共享变量, 是否有存在的必要?
    // 睡眠, 唤醒, 锁都离不开共享变量
/*      a. 情况一: 父线程创建子线程后, 自己运行(单CPU), 调用thr_join()函数. 
                这种情况下 父线程先获得lock, done==0, 子线程还在运行, 调用wait()进入睡眠; 
                子线程得以运行,  调用thr_exit()函数发送signal 信号唤醒父线程;
                父线程从wait中返回, 释放锁;
        b.  情况二: 父线程创建子线程后,子线程立即运行, 并且设置 done =1; 
                调用signal唤醒其他线程(线程队列为空), 然后结束;
                父线程运行后, 调用thr_join(), 发现done = 1, 所以释放锁返回;
*/
// 问题二:  唤醒和睡眠状态都不加锁?
    // 会被中断信号打断
#include "mutex_api.h"
#include "cond_api.h"
#include <stdio.h>
#include <assert.h>

// 共享变量的创建;
int done = 0;
// 锁和变量条件的点滴和初始化
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;

// thr_exit()  唤醒其他线程
void  thr_exit()
{
    Pthread_mutex_lock(&mutex);
    done = 1;    // test 共享变量是否需要
    Pthread_cond_signal(&cond);
    Pthread_mutex_unlock(&mutex);
}

// 子线程要做的工作
void *child( void *arg )
{
    printf("child begin : \n ");
    // child 用完之后释放
    thr_exit();

    return NULL;    // 不返回参数
}

//  睡眠等待: parent wait child thread complete;
void thr_join()
{
    Pthread_mutex_lock( &mutex );
    while( done == 0)
        Pthread_cond_wait( &cond , &mutex );
    Pthread_mutex_unlock(&mutex);   
}


// 主线程
int main(int argc, char *argv[])
{
    int rc ;
    printf("parent: begin: \n");

    pthread_t   p;
    rc = pthread_create(&p, NULL, child, NULL);     assert(rc == 0);
    thr_join();     // parent wait child thread complete;
    printf("parent : end.\n ");
}