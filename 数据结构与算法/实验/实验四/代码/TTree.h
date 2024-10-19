#ifndef exp_4
#define exp_4
#include <iostream>
#include <cstring>
#include <queue>
#include "tree.h"

using namespace std;

template<typename E> class BinTree { //二叉树类
	private:
		BinNode<E> *root; //根结点
		void clear(BinNode<E> *r) { //清空二叉树
			if (r == NULL)
				return;
			if (r->left() != NULL)
				clear(r->left());
			if (r->right() != NULL)
				clear(r->right());
			delete r;
			r = NULL;
		}
		void preOrder(BinNode<E> *tmp, void(*visit)(BinNode<E>
		              *node)) { //先序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
			if (tmp == NULL)
				return;
			visit(tmp);
			preOrder(tmp -> left(), visit);
			preOrder(tmp->right(), visit);
		}
		void inOrder( BinNode<E> *tmp, void(*visit)(BinNode<E>
		              *node)) { //中序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
			if (tmp == NULL)
				return;
			inOrder(tmp->left(), visit);
			visit(tmp);
			inOrder(tmp->right(), visit);
		}
		void postOrder(BinNode<E> *tmp, void(*visit)(BinNode<E>
		               *node)) { //后序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
			if (tmp == NULL)
				return;
			postOrder(tmp->left(), visit);
			postOrder(tmp->right(), visit);
			visit(tmp);
		}
		void LevelOrderTranverse( BinNode<E> *tmp,
		                          void(*visit)(BinNode<E>
		                                       *node)) { //层次遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
			if (tmp == NULL)
				return;
			queue<BinNode<E>*>que;
			que.push(tmp);
			BinNode<E> *curr;
			int sum = 0;
			while (que.empty() != true) {
				curr = que.front();
				if (curr ->left() != NULL)
					que.push(curr->left());
				if (curr -> right() != NULL)
					que.push(curr->right());
				que.pop();
				visit(curr);
			}
		}
		int BinTreeDepth(BinNode<E> *tmp) { //获得二叉树的深度
			if (tmp == NULL)
				return 0;
			return BinTreeHeight(tmp) - 1;
		}
		int BinTreeNodes(BinNode<E> *tmp) { //获得二叉树的结点数
			if (tmp == NULL)
				return 0;
			queue<BinNode<E>*>que;
			que.push(tmp);
			BinNode<E> *curr;
			int sum = 0;
			while (que.empty() != true) {
				curr = que.front();
				if (curr -> left() != NULL)
					que.push(curr->left());
				if (curr->right() != NULL)
					que.push(curr->right());
				que.pop();
				sum++;
			}
			return sum;
		}
		int BinTreeHeight(BinNode<E> *tmp) { //获得二叉树的高度
			if (tmp == NULL)
				return 0;
			int ld = 0;
			int rd = 0;
			if (tmp->left() != NULL)
				ld = BinTreeHeight(tmp->left());
			if (tmp->right() != NULL)
				rd = BinTreeHeight(tmp->right());
			if (ld >= rd)
				return ld + 1;
			else
				return rd + 1;
		}
		int BinTreeLeafs(BinNode<E> *tmp) { //获得二叉树的叶子结点数
			if (tmp == NULL)
				return 0;
			queue<BinNode<E>*>que;
			que.push(tmp);
			BinNode<E> *curr;
			int sum =  0;
			while (que.empty() != true) {
				curr = que.front();
				if (curr -> left() != NULL)
					que.push(curr->left());
				if (curr ->right() != NULL)
					que.push(curr->right());
				if (curr->right() == NULL && curr->left() == NULL)
					sum++;
				que.pop();
			}
			return sum;

		}
		bool find(BinNode<E> *tmp, E e) { //查找二叉树中是否含有某个名为e的结点
			if (tmp == NULL)
				return false;
			queue<BinNode<E>*>que;
			que.push(tmp);
			BinNode<E>  *curr;
			int sum = 0;
			while (que.empty() != true) {
				curr = que.front();
				if (curr->left() != NULL)
					que.push(curr->left());
				if (curr->right() != NULL)
					que.push(curr->right());
				if (curr->getValue() == e)
					return true;
				que.pop();
			}
			return false;
		}
	public:
		BinTree() { //默认构造函数
			root = new BinNode<E>;
		}
		~BinTree() { //析构函数
			clear(root);
		}
		bool BinTreeEmpty() { //判断二叉树是否为空
			if (root == NULL)
				return true;
			else
				return false;
		}
		BinNode<E> *getRoot() { //获得根节点
			return root;
		}
		void setRoot(BinNode<E> *r) { //设置根节点
			root = r;
		}
		//下面的函数是对外的函数，所以内部还会有一些同名的函数，但是参数列表不一样，实现数据的封装，外部的调用不会涉及到内部的数据对象
		void clear() { //清空二叉树
			clear(root);
			root = NULL;
		}
		void preOrder(void(*visit)(BinNode<E>
		                           *node)) { //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
			preOrder(root, visit);
		}
		void inOrder(void(*visit)(BinNode<E>
		                          *node)) { //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
			inOrder(root, visit);
		}
		void postOrder(void(*visit)(BinNode<E>
		                            *node)) { //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
			postOrder(root, visit);
		}
		void LevelOrderTranverse(void(*visit)(BinNode<E>
		                                      *node)) { //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
			LevelOrderTranverse(root, visit);
		}
		int BinTreeDepth() { //获得二叉树深度
			return BinTreeDepth(root);
		}
		int BinTreeNodes() { //获得二叉树结点数
			return BinTreeNodes(root);
		}
		int BinTreeHeight() { //获得二叉树高度
			return BinTreeHeight(root);
		}
		int BinTreeLeafs() { //获得二叉树叶子结点数
			return BinTreeLeafs(root);
		}
		bool find(E e) { //查找二叉树中是否存在名为e的结点
			return find(root, e);
		}
};
#endif