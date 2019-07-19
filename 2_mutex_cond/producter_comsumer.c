// 题目五: 典型模型: 生产者和消费者(存在界缓冲区)
/*
*   1. 解题思路注意 :
        a. 共享变量进行标识: 何时producter能进入buffer?    何时consumer能进入buffer?
        b. Mesa语义:    关于条件变量的使用, 总是使用while loop 代替if
        c. 条件变量:要具有指向性:
                消费者不能指向消费者, 只能指向生产者;
*/
#include "mutex_api.h"
#include "cond_api.h"
#include <stdio.h>

#define MAX 10      // buffer的大小
#define loops   20  // 写入和读取的次数

/***********put() and get() ways************/
//  全局变量: 存放在程序代码区(静态)
int buffer[MAX];
int fill = 0;               // 填充变量
int use = 0;            // 获取变量
int count   =   0;  //  计数

// put() funcation
void put( int value )
{
    buffer[fill] = value;
    fill    =   (fill + 1) %  MAX;
    count ++;
}
// get() funcation
int get()
{
    int tmp = buffer[use];
    use =   ( use + 1 ) % MAX;
    count --;
    return tmp;
}

/*********Producter/Consumer*********/
// 定义锁变量和条件变量
pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  empty   =   PTHREAD_COND_INITIALIZER;
pthread_cond_t  full        =   PTHREAD_COND_INITIALIZER;

//  producter 线程
void *producter( void *arg )
{
    for (int i = 0; i < loops; i++)
    {
        Pthread_mutex_lock(&mutex);
        
        while( count == MAX )
            Pthread_cond_wait(&empty, &mutex);      // 生产者进入队列: 等待条件变量为空的信号
        put(i);     // put value
        Pthread_cond_signal(&full);     // 发送条件变量为满的信号, 唤醒消费者线程队列
        
        Pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// comsumer 消费者
void    *consumer(void *arg)
{
    for (int i = 0; i < loops; i++)
    {
        Pthread_mutex_lock(&mutex);

        while( count == 0 )
            Pthread_cond_wait(&full, &mutex);   // 消费者, 等待buffer为满的信号
        int tmp = get();
        
        Pthread_cond_signal(&empty);

        Pthread_mutex_unlock(&mutex);
        printf(" %d \n ", tmp);
    }
    return NULL;
}

// 创建两个子线程, 还必须得有主线程才行;
int main(int argc, char *argv[])
{
    int rc;
    printf("parent begin:   \n ");

    pthread_t  product , consume;
    rc = pthread_create( &product, NULL, producter, NULL ); assert(rc== 0);
    rc = pthread_create(&consume, NULL, consumer, NULL);    assert(rc== 0);

    rc = pthread_join(product, NULL); assert(rc== 0);       // 只需要等待一个子线程完成, 就能代表所有的吗?
    printf("\nparent: end\n");
}