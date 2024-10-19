struct Qnode{
	BinNode<E>* node;
	int level;
};

int hleaf(BinNode* r){
	Qnode* temp,*templ,*tempr;
	queue<Qnode*> q;//层次遍历需要用到队 
	temp.node=r;
	temp.level=1;
	if(r!=NULL) 
	q.push(temp);//入队
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp.node->isLeaf())//如果找到叶结点，那么层次遍历下的离根结点最近的叶结点 
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
//时间复杂度是O（n） 
