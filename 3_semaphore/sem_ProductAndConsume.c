// 题目三: 通过信号量实现 生产者和消费者模型

/*
*   1. 解题思路注意 :
        a. 信号量的初始值进行标识: 何时producter能进入buffer?    何时consumer能进入buffer?
        b. 信号量:要具有指向性:
                消费者不能指向消费者, 只能指向生产者;
        c. 全局变量: 存放在程序代码区(静态)
        d. 还要加一个二值信号量 : 
            锁 (应对多生产者的情况)
        e. 二值信号量放置的位置, 会造成死锁的状况;


    2. 注意和条件变量实现的模型区别
        a. 不通过 count 进行记录buffer中数据的个数
        b. 操作函数换成了信号量的
            sem_wait()  and  sem_post()
*/
#include "semaphore_api.h"
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

#define MAX 10       // buffer的大小
#define loops   20  // 写入和读取的次数

/***********put() and get() ways************/

int buffer[MAX];
int fill = 0;               // 填充变量
int use = 0;            // 获取变量

// put() funcation
void put( int value )
{
    buffer[fill] = value;
    fill    =   (fill + 1) %  MAX;
}
// get() funcation
int get()
{
    int tmp = buffer[use];
    use =   ( use + 1 ) % MAX;
    return tmp;
}

/*********Producter/Consumer*********/
// 定义信号量
sem_t empty;
sem_t full;
sem_t mutex;     //  加一个二值信号量 : 作为锁

//  producter 线程
void *producter( void *arg )
{
    for (int i = 0; i < loops; i++)
    {
        // Sem_wait(&mutex);
        Sem_wait(&empty);

        Sem_wait(&mutex);
        put(i);
        Sem_post(&mutex);

        Sem_post(&full);
        // Sem_post(&mutex);
    }
    return NULL;
}

// comsumer 消费者
void    *consumer(void *arg)
{
    for (int i = 0; i < loops; i++)
    {
        // Sem_wait( &mutex);       
        Sem_wait(&full);    // full -1 < 0 , 进入等待状态, 等待full=0 的信号]

        Sem_wait( &mutex); 
        int tmp = get();
        Sem_post(&mutex);

        Sem_post(&empty);
        // Sem_post(&mutex);

        printf("%d\n", tmp);
    }
    return NULL;
}

/*************main**************/
// 创建两个子线程, 还必须得有主线程才行;
int main(int argc, char *argv[])
{
    int rc;
    printf("parent begin:   \n ");

    // 初始化信号量
    Sem_init(&empty, 0, MAX);  
    Sem_init(&full, 0, 0);
    Sem_init(&mutex, 0, 1);
    // 创建线程
    pthread_t  product , consume;
    rc = pthread_create( &product, NULL, producter, NULL ); assert(rc== 0);
    rc = pthread_create(&consume, NULL, consumer, NULL);    assert(rc== 0);

    rc = pthread_join(consume, NULL); assert(rc== 0);       // 只需要等待一个子线程完成, 就能代表所有的吗?
    printf("\nparent: end\n");
}