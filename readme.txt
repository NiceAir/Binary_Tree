����������ز�����
1. PBTNode BuyBinTreeNode(BTDataType data); // �����������Ľ��
2. void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, 3. BTDataType invalid); // ����������
4. PBTNode CopyBinTree(PBTNode pRoot); // ����������
5. void DestroyBinTree(PBTNode *pRoot); // ���ٶ�����
6. void PreOrder(PBTNode pRoot); // ǰ������ݹ�
7. void PreOrderNor(PBTNode pRoot); // ǰ������ǵݹ�
8. void InOrder(PBTNode pRoot); // ��������ݹ�
9. void InOrderNor(PBTNode pRoot); // ��������ǵݹ�
10.void PostOrder(PBTNode pRoot); // ��������ݹ�
11.void PostOrderNor(PBTNode pRoot); // ��������ǵݹ�
12.void LevelOrder(PBTNode pRoot); // ���������������ȱ�����
13.void MirrorBinTree(PBTNode pRoot); // �������ľ���ݹ� 
14.void MirrorBinTreeNor(PBTNode pRoot); // �������ľ���ǵݹ� 
15.int BinTreeSize(PBTNode pRoot); // ��������н��ĸ��� 
16.int GetLeafCount(PBTNode pRoot); // ��ȡ��������Ҷ�ӽ��ĸ���
17.int GetKLevelNode(PBTNode pRoot, int K); // ���������K����ĸ��� 
18.int Height(PBTNode pRoot); // ��������ĸ߶�