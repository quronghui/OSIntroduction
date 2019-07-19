// 题目四 : 信号量实现---读者--写者锁实现方式?

/*  - 读者锁: 一旦一个读者获得读锁, 其他读者也能获得该锁;
 *   - 写者锁: 但是想要获得写者锁, 必须等待所有的读者结束; 
*/

#include "semaphore_api.h"
#include <stdio.h>

// 定义结构体参数
typedef struct sem_read_write
{
    sem_t lock;     // binary semaphore (basic lock)
    sem_t   writelock;      // used to allow one_write  or  more_reads
    int     readers;
}rwlock_t;

// 初始化参数
void rwlock_init( rwlock_t *rw )
{
    rw->readers = 0;
    Sem_init(&rw->lock, 0, 1 );
    Sem_init( &rw->writelock, 0, 1 );
}

//  读者申请读锁
void rwlock_acquire_readlock( rwlock_t *rw )
{
    Sem_wait(&rw->lock);
    rw->readers ++;
    if( rw->readers == 1 )
        Sem_wait( &rw->writelock );     // 只要有一个读者获取到读锁, 那么写锁就会一直处于睡眠
    Sem_post(&rw->lock);
}

// 读者释放读锁
void rwlock_release_readlock( rwlock_t *rw )
{
    Sem_wait(&rw->lock);
    rw->readers--;
    if( rw->readers == 0 )
        Sem_post(&rw->writelock);       // 最后一个读者释放锁时, 写锁线程被唤醒;
    Sem_post( &rw->lock );
}

// 申请写锁
void rwlock_acquire_writelock(rwlock_t  *rw)
{
    Sem_wait( &rw->writelock );
}

// 释放写锁
void rwlock_release_writelock( rwlock_t *rw )
{
    Sem_post( &rw->writelock );
}