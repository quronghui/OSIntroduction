// 题目一:  初始化锁和获取锁
#include "mutex_api.h"

// 锁的初始化
void Pthread_mutex_init(pthread_mutex_t *mutex)
{
	int rc = pthread_mutex_init(mutex, NULL );
	assert(rc == 0);
}

// 获取锁, 为了检查是够获取成功; 不然保证不了临界区的互斥
void Pthread_mutex_lock( pthread_mutex_t *mutex ){
	int rc = pthread_mutex_lock(mutex);
	assert(rc==0);
}

// 释放锁, 为了检查是够释放成功;
void Pthread_mutex_unlock( pthread_mutex_t *mutex ){
	int rc = pthread_mutex_unlock(mutex);
	assert(rc==0);
}

// // 临界区的使用
void *mythread(void *arg)
{
	pthread_mutex_t lock;
  	Pthread_mutex_init(&lock);
	// 领街区的代码使用
	Pthread_mutex_lock(&lock);
	int x = x+1;	
	Pthread_mutex_unlock(&lock);
}


// 创建两个子线程, 还必须得有主线程才行;
int main(int argc, char *argv[])
{
    int rc;
    printf("parent begin:   \n ");

    pthread_t  p;
    rc = pthread_create( &p, NULL, mythread, NULL ); assert(rc== 0);

    rc = pthread_join(p, NULL); assert(rc== 0);       // 只需要等待一个子线程完成, 就能代表所有的吗?
    printf("\nparent: end\n");
}
