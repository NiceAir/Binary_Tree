//静态顺序栈
#ifndef _STATIC_ORDER_STACK_H
#define _STATIC_ORDER_STACK_H
#include "common.h"
void StaticStackTest(void); //测试静态栈
void StaticStackInit(SStack *Stack); //静态栈的初始化
int CheckStackIsFull(const SStack stack);    //检查栈是否满, 没满返回0，满了返回1
int StackPush(SStack *stack, SNode node);//元素入栈,成功返回1，失败返回0
int CheckStackIsEmpty(const SStack stack);//检查栈是否为空,为空返回0。不为空返回1
SNode StackPop(SStack *stack);//元素出栈。出栈成功返回出来的元素，出栈失败则程序退出
int GetStackNodeCount(const SStack stack);  //获取栈中元素个数
SNode GetStackTop(const SStack stack);   //获取栈顶元素

#endif