#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H


#include "StaticOrderStack.h"
#include "common.h"
#include "SequentialLoopQueue.h"

PBTNode BuyBinTreeNode(BTDataType data); // �����������Ľ��
void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid); // ����������
PBTNode CopyBinTree(PBTNode pRoot); // ����������
void DestroyBinTree(PBTNode *pRoot); // ���ٶ�����
void PreOrder(PBTNode pRoot); // ǰ������ݹ�
void PreOrderNor(PBTNode pRoot); // ǰ������ǵݹ�
void InOrder(PBTNode pRoot); // ��������ݹ�
void InOrderNor(PBTNode pRoot); // ��������ǵݹ�
void PostOrder(PBTNode pRoot); // ��������ݹ�
void PostOrderNor(PBTNode pRoot); // ��������ǵݹ�
void LevelOrder(PBTNode pRoot); // ���������������ȱ�����
void MirrorBinTree(PBTNode pRoot); // �������ľ���ݹ� 
void MirrorBinTreeNor(PBTNode pRoot); // �������ľ���ǵݹ� 
int BinTreeSize(PBTNode pRoot); // ��������н��ĸ��� 
int GetLeafCount(PBTNode pRoot); // ��ȡ��������Ҷ�ӽ��ĸ���
int GetKLevelNode(PBTNode pRoot, int K); // ���������K����ĸ��� 
int Height(PBTNode pRoot); // ��������ĸ߶�

#endif
