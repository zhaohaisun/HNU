//全局变量法 
int count;
void countleaf(BinNode<E>* subroot){
	if(subroot==NULL) return;
	if(subroot->isleaf()) count++;
	countleaf(subroot->left());
	countleaf(subroot->right());
}
//函数的变参
void countleaf(BinNode<E>* subroot,int& count){
	if(subroot){
		if(subroot->isLeaf())
		count++;
		countleaf(subroot->left());
	    countleaf(subroot->right());
	}
}
//若被限制条件的情况下
 int  countleaf(BinNode<E>* subroot)//获得二叉树的叶子结点数
    {
        if (subroot == NULL) return 0;
        if (subroot->isleaf()) return 1;
        return countleaf(subroot->left()) + countleaf(subroot->right());
    }

//时间复杂度O（n），空间复杂度O（n） 
