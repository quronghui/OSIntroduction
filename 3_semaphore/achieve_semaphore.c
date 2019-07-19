// 题目五:  通过锁和条件变量实现 信号量
//
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

typedef struct achieve_semaphore
{
    int value;                  // 共享变量, 用于同步;  代表信号量里面的整数值
    pthread_mutex_t lock;   // lock, 提供互斥条件
    pthread_cond_t  cond;   // cond, 条件变量, 进行线程间的等待和唤醒机制
}Zem_t ;

// only one thread can call this
void Zem_init( Zem_t *s, int value )
{
    int rc ;
    s->value = value;
    rc = pthread_mutex_init( &s->lock, NULL);   assert(rc==0);
    rc  = pthread_cond_init(&s->cond, NULL);    assert(rc==0);
}

// Zem_wait()等待
void Zem_wait( Zem_t *s )
{
    int rc;
    rc = pthread_mutex_lock(&s->lock);  assert(rc==0);

    while( s->value <= 0 )      // 信号量小于0, 就进入等待, 然后释放锁;
        rc = pthread_cond_wait(&s->cond, &s->lock);
    s->value--;

    rc = pthread_mutex_unlock(&s->lock);  assert(rc==0);

}

// Zem_post() 唤醒
void Zem_post(Zem_t *s)
{
    int rc ;
    rc = pthread_mutex_lock(&s->lock);  assert(rc==0);
    
    s->value ++;
    rc = pthread_cond_signal(&s->cond);     assert(rc==0);

    rc = pthread_mutex_unlock(&s->lock);  assert(rc==0);


}