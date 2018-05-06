
#include "StaticOrderStack.h"

void StaticStackInit(SStack *Stack) //��̬ջ�ĳ�ʼ��
{
    assert(Stack);
    Stack->bottom = 0;
    Stack->top = 0;
}

int CheckStackIsFull(const SStack stack)    //���ջ�Ƿ���, û������0�����˷���1
{
    return ((stack.top) < MAXLEN)?0:1;
}

int StackPush(SStack *stack, SNode node)    //Ԫ����ջ,�ɹ�����1��ʧ�ܷ���0
{
    assert(stack);
    if (!CheckStackIsFull(*stack))
    {
        stack->top++;
        stack->Node[stack->top-1] = node;
        return 1;
    }
    printf("ջ��������ջʧ��\n");
    return 0;
}

int CheckStackIsEmpty(const SStack stack)//���ջ�Ƿ�Ϊ��,Ϊ�շ���0����Ϊ�շ���1
{
    return stack.top <= stack.bottom ? 1 : 0;
}

SNode StackPop(SStack *stack)//Ԫ�س�ջ����ջ�ɹ����س�����Ԫ�أ���ջʧ��������˳�
{
    assert(stack);
    if (!CheckStackIsEmpty(*stack))
    {
        SNode node = stack->Node[stack->top-1];
        stack->top--;
        return node;
    }
    else
    {
        printf("ջ�ѿգ���ջʧ��\n");
        exit(0);
    }
}

int GetStackNodeCount(const SStack stack)  //��ȡջ��Ԫ�ظ���
{
    return (stack.top)-(stack.bottom);
}

SNode GetStackTop(const SStack stack)   //��ȡջ��Ԫ��
{
    if(!CheckStackIsEmpty(stack))
        return stack.Node[stack.top-1]; 
    else
        printf("����ջΪ��\n");
}
