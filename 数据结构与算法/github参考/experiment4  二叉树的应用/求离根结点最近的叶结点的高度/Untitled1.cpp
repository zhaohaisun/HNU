struct Qnode{
	BinNode<E>* node;
	int level;
};

int hleaf(BinNode* r){
	Qnode* temp,*templ,*tempr;
	queue<Qnode*> q;//��α�����Ҫ�õ��� 
	temp.node=r;
	temp.level=1;
	if(r!=NULL) 
	q.push(temp);//���
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp.node->isLeaf())//����ҵ�Ҷ��㣬��ô��α����µ������������Ҷ��� 
		return temp.level;
		if(temp.node->left()!=NULL){
			templ.node=temp.node->left();
			templ.level=temp.level+1;
			q.push(templ);
		} 
		if(temp.node->right()!=NULL){
			tempr.node=temp.node->right();
			tempr.level=temp.level+1;
			q.push(tempr);
		}
	} 
}
//ʱ�临�Ӷ���O��n�� 
