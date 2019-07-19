// 题目三: 线程的完成
/*
*   1. 代码思路: 主函数初始化一个结构体的值, 创建线程进行值的打印;
                            然后线程中初始化另外一个结构体, 返回到主函数进行打印;
    2. 如果只传递一个值, 就不需要不停地打包和解包
    3. 注意: 
        mythread的返回值, 不能是指针
*/
#include  <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

/******** 1.将参数不停地打包和解包, 从而构建原子性, 因为要传两个值********/
typedef struct myarg_t{
    int a;
    int b;
}myarg_t;

typedef struct myret_t{
    int x;
    int y;
}myret_t;

// pthread_create 的第三个参数, 函数指针
void *mythread(void *arg){
    myarg_t *m = (myarg_t *)arg;    //强制转换
    printf("args.a = %d args.b = %d\n", m->a, m->b);

    // 创建另外一个指针, 重新赋值后,返回主函数打印
    myret_t *r = malloc (sizeof(myret_t));
    r->x = 1;
    r->y = 2;
    return (void *)r;       // 我们此时返回的, 是*r;

    // // 返回值不能是指针
    // myret_t     r ;                //r分配的是 栈内存, 返回的时候被释放了
    // r.x = 1;
    // r.y = 2;
    // return (void *)&r;       // 我们此时返回的, 是*r;
}

int main(int argv, char *argc[])
{
    int rc;
    pthread_t p;    //  pthread_create 参数1
    
    myret_t *m;
    myarg_t args;   // pthread_create 参数4
    args.a = 10; args.b = 20;

    rc = pthread_create(&p, NULL, mythread, &args);     assert(rc == 0);
    rc = pthread_join(p, (void **)&m);    assert(rc == 0);                       // 加强制函数说明 (void **)&m
    
    printf(" return value %d %d.\n ", m->x, m->y);      // 输出返回的值
}