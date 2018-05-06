#include "BinaryTree.h"

int main()
{
    PBTNode Btnode = NULL;
    PBTNode BtnodeSecond = NULL;
    BTDataType arr[] = "ABD###CE##F";
    int len  = strlen(arr);
    CreateBinTree(&Btnode, arr, len, '#');

    printf("��������ݹ飺");
    PreOrder(Btnode);
    printf("\n");
    printf("��������ǵݹ飺");
    PreOrderNor(Btnode);
    printf("\n\n");

    printf("��������ݹ飺");
    InOrder(Btnode);
    printf("\n");
    printf("��������ǵݹ飺");
    InOrderNor(Btnode);
    printf("\n\n");

    printf("��������ݹ飺");
    PostOrder(Btnode);
    printf("\n");
    printf("��������ǵݹ飺");
    PostOrderNor(Btnode);
    printf("\n\n");

    BtnodeSecond = CopyBinTree(Btnode);
    printf("��������ݹ鿽��������");
    PreOrder(BtnodeSecond);
    printf("\n");
    DestroyBinTree(&BtnodeSecond);
    printf("��������ݹ����ٺ�����");
    PreOrder(BtnodeSecond);
    printf("\n\n");

    printf("�������(������ȱ���)��");
    LevelOrder(Btnode);
    printf("\n\n");

    MirrorBinTree(Btnode);
    printf("�ݹ龵�����������");
    LevelOrder(Btnode);
    printf("\n");
    MirrorBinTreeNor(Btnode);
    printf("�Ǿ���ݹ����������");
    LevelOrder(Btnode);
    printf("\n\n");

    printf("�������н��ĸ���Ϊ:%d\n", BinTreeSize(Btnode));
    printf("��������Ҷ�ӵĸ���Ϊ:%d\n", GetLeafCount(Btnode));
    printf("�������е�1����ĸ���Ϊ:%d\n", GetKLevelNode(Btnode, 1));
    printf("�������е�2����ĸ���Ϊ:%d\n", GetKLevelNode(Btnode, 2));
    printf("�������е�2����ĸ���Ϊ:%d\n", GetKLevelNode(Btnode, 3));
    printf("�������еĸ߶�Ϊ:%d\n", Height(Btnode));
    return 0;
}