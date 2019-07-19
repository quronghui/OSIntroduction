// 题目五: 哲学家就餐问题?
// 问题: 哲学家只有同时拿到左手边和右手边的餐叉, 才能吃到东西? 如何进行同步;

// 每个哲学家的基本循环
/*void  eatting(){
    while(1){
        think();          // 哲学家的思考;
        getfork();      // 拿到餐叉
        eat();
        putfork();      // 放开餐叉
    }
}
*/

#include "semaphore_api.h"
#include <stdio.h>

/*****************实现上面的函数*******************/ 
#define MAX 5

sem_t  fork[MAX];     // 假设有五个餐叉, 五位哲学家就餐;
int p;                              // 代表几号餐叉: 0-4

// 左边的餐叉;
int left( int p){
    return p;
}

// 右边的餐叉
int right(int p){
    return (p+1) % MAX;
}

// 初始化
void fork_init()
{
    for (int i = 0; i < MAX; i++){
        Sem_init(&fork[i], 0, 1);
    }
}

// putfork()
void putfork()
{
    Sem_post( &fork[left(  p )] );   // 顺序从0-4
    Sem_post(&fork[right(p) ] );
}

// getfork()    : 防止出现死锁的状况
void getfork()
{
    if( p == MAX-1 ){       // 换一下拿叉子的顺序
        Sem_wait( &fork[ right(p) ] );
        Sem_wait( &fork[ left(p) ] );
    }
    else {
        Sem_wait( &fork[ left(p) ] );        
        Sem_wait( &fork[ right(p) ] );
    }
}