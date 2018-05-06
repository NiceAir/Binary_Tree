#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 100

// *************************BinatyTree.h***************************
typedef char BTDataType; 
typedef struct BinTreeNode 
{ 
    BTDataType _data; 
    struct BinTreeNode* _pLeft; 
    struct BinTreeNode* _pRight; 
}BTNode, *PBTNode; 


typedef struct SNode{
    PBTNode pbtnode;
}SNode;

//************************StaticOrderStack.h*************************
typedef struct StaticStack{
    int top;
    int bottom;
    SNode Node[MAXLEN];
}SStack;

//*************************SequentialLoopQueue.h***********************

typedef struct CircleQueue{
    int front;
    int tail;
    SNode Node[MAXLEN];
}CQueue;

