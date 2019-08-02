// 题目五:  基于硬件原语 -- 实现 自旋锁: 
/*
*   思路一: Test And Set 实现锁
*   思路二: CompareAndSwap 实现锁
*/
#include <stdio.h>

// 定义互斥量
typedef struct spin_lock
{
    int flag;
} lock_t;

/******************思路一: Test And Set 实现锁**********************/ 
int TestAndSet( int *old_ptr, int new )
{
    int old = *old_ptr;
    old_ptr = new;

    return old;
}

// 变量的初始化, 0表示锁是空闲的; 1 表示锁被占用
void init( lock_t *lock){
    lock->flag = 0;
}

// 获取锁
void lock( lock_t *lock ){

    while( TestAndSet( &lock->flag, 1 ) == 1 )
        ;       // spin waitting ( do nothing )
}

// 释放锁
void unlock(lock_t *lock)
{
    lock->flag = 0;
}
/*******************思路二: CompareAndSwap 实现锁***********************/
// CompareAndSwap原子操作
int CompareAndSwap( int *ptr, int expected, int new )
{
    int actual = *ptr;
    if( actual == expected )    // 比较进行交换
        *ptr = new;
    
    return actual;
}

// 获取锁
void lock(lock_t *lock){
    while( CompareAndSwap( &lock->flag, 0, 1 ) == 1 )
        ;   // spin waitting
}

