## 2_mutex_cond

+ 锁 和 条件变量 实现线程间的互斥和同步

1. mutex_api.c mutex_api.h

   ```
   题目一:  初始化锁和获取锁. 通过assert进行一个判断
   ```

2. spin_lock.c

   ```
   // 题目五:  基于硬件原语 -- 实现 自旋锁: 
   ```

3. cond_api.c  cond_api.h

   ```
    题目二:  条件变量的创建和使用
   ```

4. condition_vailable.c

   ```
   题目三: 通过条件变量和锁实现原子操作 -- 父进程等待子进程的运行
   ```

5. producter_comsumer.c 

   ```
   题目四: 通过条件变量和锁实现典型模型  --  生产者和消费者(存在界缓冲区)
   ```

