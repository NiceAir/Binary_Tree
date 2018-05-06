//顺序循环队列
#ifndef _SEQUENTIAL_LOOP_QUEUE_H
#define _SEQUENTIAL_LOOP_QUEUE_H
#include "common.h"
void CircleQueueInit(CQueue *queue);    //顺序循环队列初始化
int CheckQueueIsFull(const CQueue queue);//判断队列是否满了。队列满则返回1，没满则返回0。
void QueuePush(CQueue *queue, SNode node);//元素入队列
int CheckQueueIsEmpty(const CQueue queue);//判断队列是否为空。为空则返回1，否则返回0。
SNode QueuePop(CQueue *queue); //元素出队列
int GetQueueCount(const CQueue queue); //获取队列中元素的个数
SNode GetQueueTop(const CQueue queue); //获取最后进队列的元素
SNode GetQueueTail(const CQueue queue); //获取最早进队列的元素
#endif