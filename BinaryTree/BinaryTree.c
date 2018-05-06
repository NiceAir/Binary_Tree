#include "BinaryTree.h"

PBTNode BuyBinTreeNode(BTDataType data)// 构建二叉树的结点
{
    PBTNode btnode = (PBTNode)malloc(sizeof(BTNode));
    if (btnode != NULL)
    {
        btnode->_data = data;
        btnode->_pLeft = NULL;
        btnode->_pRight = NULL;
        return btnode;
    }
    return NULL;
}

static void _CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, int *index, BTDataType invalid) // 递归地创建二叉树
{
    if (*index < size)
    {
        BTDataType cache = array[(*index)++]; 
        if (cache == invalid)
            *pRoot = NULL;
        else
        {
            *pRoot = BuyBinTreeNode(cache);
            _CreateBinTree(&((*pRoot)->_pLeft), array, size, index, invalid);
            _CreateBinTree(&((*pRoot)->_pRight), array, size, index, invalid);
        }
    }
}
void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid) // 调用_CreateBinTree创建二叉树
{
    int index = 0;
    assert(pRoot);
    assert(array);
    _CreateBinTree(pRoot, array, size, &index, invalid);
}

PBTNode CopyBinTree(PBTNode pRoot) // 拷贝二叉树
{
    PBTNode pRootSecond = NULL;
    if (pRoot == NULL)
        return NULL;
    
    pRootSecond = BuyBinTreeNode(pRoot->_data);
    pRootSecond->_pLeft = CopyBinTree(pRoot->_pLeft);
    pRootSecond->_pRight = CopyBinTree(pRoot->_pRight);

    return pRootSecond;
}

void DestroyBinTree(PBTNode *pRoot) // 销毁二叉树
{
    PBTNode cache = NULL; 
    assert(pRoot);
    if ((*pRoot)->_pLeft != NULL)
        DestroyBinTree(&((*pRoot)->_pLeft));
    if ((*pRoot)->_pRight != NULL)
        DestroyBinTree(&((*pRoot)->_pRight));
    free(*pRoot);
    *pRoot = NULL;
}

void PreOrder(PBTNode pRoot) // 前序遍历递归
{
    if (pRoot != NULL)
    {
        printf("%c ", pRoot->_data);
        PreOrder(pRoot->_pLeft);
        PreOrder(pRoot->_pRight);
    }
}

void PreOrderNor(PBTNode pRoot) // 前序遍历非递归
{
   SStack stack;
   SNode node;
   node.pbtnode = pRoot;
   StaticStackInit(&stack);
   StackPush(&stack,node);
   while(!CheckStackIsEmpty(stack))
   {
        pRoot = GetStackTop(stack).pbtnode;
        printf("%c ", pRoot->_data);
        StackPop(&stack);
        if (pRoot->_pRight != NULL)
        {
            node.pbtnode = pRoot->_pRight;
            StackPush(&stack,node);
        }
        if (pRoot->_pLeft != NULL)
        {
            node.pbtnode = pRoot->_pLeft;
            StackPush(&stack,node);
        }
   }
}

void InOrder(PBTNode pRoot) // 中序遍历递归
{
    if (pRoot != NULL)
    {
        InOrder(pRoot->_pLeft);
        printf("%c ", pRoot->_data);
        InOrder(pRoot->_pRight);
    }
}

void InOrderNor(PBTNode pRoot) // 中序遍历非递归
{
    SStack stack;
    SNode node;
    node.pbtnode = pRoot;
    StaticStackInit(&stack);
    StackPush(&stack,node);
    pRoot = pRoot->_pLeft;
    while(!CheckStackIsEmpty(stack))
    {
        while(pRoot != NULL)
        {
            node.pbtnode = pRoot;
            StackPush(&stack,node);
            pRoot = pRoot->_pLeft;         
        }
        pRoot = GetStackTop(stack).pbtnode;
        printf("%c ", pRoot->_data);
        StackPop(&stack);
        pRoot = pRoot->_pRight;
        if (pRoot != NULL)
        {
            node.pbtnode = pRoot;
            StackPush(&stack,node);
            pRoot = pRoot->_pLeft;
        } 
    }
}

void PostOrder(PBTNode pRoot) // 后序遍历递归
{
    if (pRoot != NULL)
    {
        PostOrder(pRoot->_pLeft);
        PostOrder(pRoot->_pRight);
        printf("%c ", pRoot->_data);
    }
}

void PostOrderNor(PBTNode pRoot) // 后序遍历非递归
{
    SStack stack;
    SNode node;
    int flag[100];      //用来标记结点的右子树是否被访问过
    int i = 0;
    node.pbtnode = pRoot;
    StaticStackInit(&stack);
    StackPush(&stack,node);
    pRoot = pRoot->_pLeft;
    while(!CheckStackIsEmpty(stack))
    {
        while(pRoot != NULL)
        {
            node.pbtnode = pRoot;
            StackPush(&stack, node);
            i++;
            pRoot = pRoot->_pLeft;
        }
        pRoot = GetStackTop(stack).pbtnode;
        if (pRoot->_pRight != NULL && flag[i] != 1)
        {
            pRoot = pRoot->_pRight;
            node.pbtnode = pRoot;
            StackPush(&stack, node);
            flag[i] = 1;
            i++;
            pRoot = pRoot->_pLeft;
        }
        else
        {
            printf("%c ", pRoot->_data);
            StackPop(&stack);
            pRoot = NULL;
            i--;
        }
    }
}


void LevelOrder(PBTNode pRoot) // 层序遍历（广度优先遍历）
{
    CQueue queue;
    SNode node;
    CircleQueueInit(&queue);
    node.pbtnode = pRoot;
    QueuePush(&queue,node);
    
    while(!CheckQueueIsEmpty(queue))
    {
        if (pRoot->_pLeft != NULL)
        {
            node.pbtnode = pRoot->_pLeft;
            QueuePush(&queue,node);
        }
        if (pRoot->_pRight != NULL)
        {
            node.pbtnode = pRoot->_pRight;
            QueuePush(&queue, node);
        }
        printf("%c ", GetQueueTail(queue).pbtnode->_data);
        QueuePop(&queue);
        if (!CheckQueueIsEmpty(queue))
            pRoot = GetQueueTail(queue).pbtnode;
    }
}

static void SwapBTNode(PBTNode pRoot)    //交换一个结点的左右孩子
{
    BTNode *cache = pRoot->_pLeft;
    pRoot->_pLeft = pRoot->_pRight;
    pRoot->_pRight = cache;    
}

void MirrorBinTree(PBTNode pRoot) // 二叉树的镜像递归 
{
    if (pRoot->_pLeft != NULL || pRoot->_pRight != NULL)
        SwapBTNode(pRoot);
    if (pRoot->_pLeft != NULL)
        MirrorBinTree(pRoot->_pLeft);
    if (pRoot->_pRight != NULL)
        MirrorBinTree(pRoot->_pRight);
}

void MirrorBinTreeNor(PBTNode pRoot) // 二叉树的镜像非递归
{
    CQueue queue;
    SNode node;
    CircleQueueInit(&queue);
    node.pbtnode = pRoot;
    QueuePush(&queue,node);

    while(!CheckQueueIsEmpty(queue))
    {
        pRoot = GetQueueTail(queue).pbtnode;
        if (pRoot->_pLeft != NULL)
        {
            node.pbtnode = pRoot->_pLeft;
            QueuePush(&queue,node);
        }
        if (pRoot->_pRight != NULL)
        {
            node.pbtnode = pRoot->_pRight;
            QueuePush(&queue, node);
        }
        SwapBTNode(pRoot);
        QueuePop(&queue);
    }

}

int BinTreeSize(PBTNode pRoot) // 求二叉树中结点的个数
{
    if (pRoot != NULL)
    {
        if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
            return 1;
        return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
    }
    return 0;
}

int GetLeafCount(PBTNode pRoot) // 获取二叉树中叶子结点的个数
{
    if (pRoot != NULL)
    {
        int a = 0;
        int b = 0;
        if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
            return 1;
        return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
    }
    return 0;
}

int GetKLevelNode(PBTNode pRoot, int K) // 求二叉树中第K层结点的个数
{
    if (K == 1 )
    {   
        if (pRoot)
            return 1;
        return 0;
    }
    return GetKLevelNode(pRoot->_pLeft, K-1) + GetKLevelNode(pRoot->_pRight, K-1);
}

static my_max(int a, int b)
{
    return a>b?a:b;
}

int Height(PBTNode pRoot) // 求二叉树的高度
{
    if (pRoot)
    {
        if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
            return 1;
        return my_max(Height(pRoot->_pLeft), Height(pRoot->_pRight)) + 1;
    }
    return 0; 
}
