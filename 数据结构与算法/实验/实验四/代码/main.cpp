#include <iostream>
#include <cstring>
#include <cstdio>
#include "tree.h"
#include "TTree.h"
using namespace std;

BinNode<int> *creatBinaryTree() {
	char c;
	cin >> c;
	if (c == '#')
		return NULL;
	BinNode<int> *root = new BinNode<int>;
	root->setValue((int)c - 48);
	root->setLeft(creatBinaryTree());
	root->setRight(creatBinaryTree());
	return root;
}

BinNode<int> *mergeTrees(BinNode<int> *t1, BinNode<int> *t2) {
	if (t2 == NULL)
		return t1;
	if (t1 == NULL)
		return t2;
	BinNode<int> *tmp = new BinNode<int>;
	tmp->setValue(t1->getValue() + t2->getValue());
	tmp->setLeft(mergeTrees(t1->left(), t2->left()));
	tmp->setRight(mergeTrees(t1->right(), t2->right()));
	return tmp;
}

void printNode(BinNode<int> *root) {
	if (root) {
		cout << root->getValue();
		printNode(root->left());
		printNode(root->right());
	} else
		printf("#");
}

int main() {

	BinNode<int> *root1, * root2;
	root1 = new BinNode<int>;
	root2 = new BinNode<int>;
	root1 = creatBinaryTree();
	root2 = creatBinaryTree();
	BinNode<int> *ans = mergeTrees(root1, root2);
	printNode(ans);
	return 0;
}
