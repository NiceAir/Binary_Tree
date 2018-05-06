#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H


#include "StaticOrderStack.h"
#include "common.h"
#include "SequentialLoopQueue.h"

PBTNode BuyBinTreeNode(BTDataType data); // 构建二叉树的结点
void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid); // 创建二叉树
PBTNode CopyBinTree(PBTNode pRoot); // 拷贝二叉树
void DestroyBinTree(PBTNode *pRoot); // 销毁二叉树
void PreOrder(PBTNode pRoot); // 前序遍历递归
void PreOrderNor(PBTNode pRoot); // 前序遍历非递归
void InOrder(PBTNode pRoot); // 中序遍历递归
void InOrderNor(PBTNode pRoot); // 中序遍历非递归
void PostOrder(PBTNode pRoot); // 后序遍历递归
void PostOrderNor(PBTNode pRoot); // 后序遍历非递归
void LevelOrder(PBTNode pRoot); // 层序遍历（广度优先遍历）
void MirrorBinTree(PBTNode pRoot); // 二叉树的镜像递归 
void MirrorBinTreeNor(PBTNode pRoot); // 二叉树的镜像非递归 
int BinTreeSize(PBTNode pRoot); // 求二叉树中结点的个数 
int GetLeafCount(PBTNode pRoot); // 获取二叉树中叶子结点的个数
int GetKLevelNode(PBTNode pRoot, int K); // 求二叉树中K层结点的个数 
int Height(PBTNode pRoot); // 求二叉树的高度

#endif
