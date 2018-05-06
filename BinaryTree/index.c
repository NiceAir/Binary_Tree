#include "BinaryTree.h"

int main()
{
    PBTNode Btnode = NULL;
    PBTNode BtnodeSecond = NULL;
    BTDataType arr[] = "ABD###CE##F";
    int len  = strlen(arr);
    CreateBinTree(&Btnode, arr, len, '#');

    printf("先序遍历递归：");
    PreOrder(Btnode);
    printf("\n");
    printf("先序遍历非递归：");
    PreOrderNor(Btnode);
    printf("\n\n");

    printf("中序遍历递归：");
    InOrder(Btnode);
    printf("\n");
    printf("中序遍历非递归：");
    InOrderNor(Btnode);
    printf("\n\n");

    printf("后序遍历递归：");
    PostOrder(Btnode);
    printf("\n");
    printf("后序遍历非递归：");
    PostOrderNor(Btnode);
    printf("\n\n");

    BtnodeSecond = CopyBinTree(Btnode);
    printf("先序遍历递归拷贝后结果：");
    PreOrder(BtnodeSecond);
    printf("\n");
    DestroyBinTree(&BtnodeSecond);
    printf("先序遍历递归销毁后结果：");
    PreOrder(BtnodeSecond);
    printf("\n\n");

    printf("层序遍历(广度优先遍历)：");
    LevelOrder(Btnode);
    printf("\n\n");

    MirrorBinTree(Btnode);
    printf("递归镜像后层序遍历：");
    LevelOrder(Btnode);
    printf("\n");
    MirrorBinTreeNor(Btnode);
    printf("非镜像递归后层序遍历：");
    LevelOrder(Btnode);
    printf("\n\n");

    printf("二叉树中结点的个数为:%d\n", BinTreeSize(Btnode));
    printf("二叉树中叶子的个数为:%d\n", GetLeafCount(Btnode));
    printf("二叉树中第1层结点的个数为:%d\n", GetKLevelNode(Btnode, 1));
    printf("二叉树中第2层结点的个数为:%d\n", GetKLevelNode(Btnode, 2));
    printf("二叉树中第2层结点的个数为:%d\n", GetKLevelNode(Btnode, 3));
    printf("二叉树中的高度为:%d\n", Height(Btnode));
    return 0;
}