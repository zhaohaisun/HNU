//ȫ�ֱ����� 
int count;
void countleaf(BinNode<E>* subroot){
	if(subroot==NULL) return;
	if(subroot->isleaf()) count++;
	countleaf(subroot->left());
	countleaf(subroot->right());
}
//�����ı��
void countleaf(BinNode<E>* subroot,int& count){
	if(subroot){
		if(subroot->isLeaf())
		count++;
		countleaf(subroot->left());
	    countleaf(subroot->right());
	}
}
//�������������������
 int  countleaf(BinNode<E>* subroot)//��ö�������Ҷ�ӽ����
    {
        if (subroot == NULL) return 0;
        if (subroot->isleaf()) return 1;
        return countleaf(subroot->left()) + countleaf(subroot->right());
    }

//ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��n�� 
