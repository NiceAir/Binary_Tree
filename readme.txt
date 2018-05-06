二叉树的相关操作：
1. PBTNode BuyBinTreeNode(BTDataType data); // 构建二叉树的结点
2. void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, 3. BTDataType invalid); // 创建二叉树
4. PBTNode CopyBinTree(PBTNode pRoot); // 拷贝二叉树
5. void DestroyBinTree(PBTNode *pRoot); // 销毁二叉树
6. void PreOrder(PBTNode pRoot); // 前序遍历递归
7. void PreOrderNor(PBTNode pRoot); // 前序遍历非递归
8. void InOrder(PBTNode pRoot); // 中序遍历递归
9. void InOrderNor(PBTNode pRoot); // 中序遍历非递归
10.void PostOrder(PBTNode pRoot); // 后序遍历递归
11.void PostOrderNor(PBTNode pRoot); // 后序遍历非递归
12.void LevelOrder(PBTNode pRoot); // 层序遍历（广度优先遍历）
13.void MirrorBinTree(PBTNode pRoot); // 二叉树的镜像递归 
14.void MirrorBinTreeNor(PBTNode pRoot); // 二叉树的镜像非递归 
15.int BinTreeSize(PBTNode pRoot); // 求二叉树中结点的个数 
16.int GetLeafCount(PBTNode pRoot); // 获取二叉树中叶子结点的个数
17.int GetKLevelNode(PBTNode pRoot, int K); // 求二叉树中K层结点的个数 
18.int Height(PBTNode pRoot); // 求二叉树的高度