#ifndef reliseADT 
#define reliseADT 
#include "ADT.h"
#include "string"
#include <iostream>
#include <queue>

template<typename  E>
class  BinTree :public binTree<E>//二叉树类
{
private:
    BinNode<E>* root;//根结点
    void  clear(BinNode<E>* r)//清空二叉树
    {

        if (r == NULL) return;
        clear(r->left());
        clear(r->right());
        delete r;

    }
    void  preOrder(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//先序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {

        if (tmp != NULL) {
            visit(tmp);
            preOrder(tmp->left(), visit);
            preOrder(tmp->right(), visit);
        }

    }
    void  inOrder(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//中序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {

        if (tmp != NULL) {
            inOrder(tmp->left(), visit);
            visit(tmp);
            inOrder(tmp->right(), visit);
        }

    }
    void  postOrder(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//后序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {

        if (tmp != NULL) {
            postOrder(tmp->left(), visit);
            postOrder(tmp->right(), visit);
            visit(tmp);
        }

    }
    void  LevelOrderTranverse(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//层次遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
    {

        queue<BinNode<E>*> q;
        if (tmp != NULL) { q.push(tmp); }//压入队尾
        BinNode<E>* b;
        while (!q.empty()) {
            b = q.front();//b等于队头元素
            visit(b);
            q.pop();//弹出队头元素
            if (b->left()) {
                q.push(b->left());//压入b的左孩子
            }
            if (b->right()) {
                q.push(b->right());//压入b的右孩子
            }
        }

    }
    int  BinTreeDepth(BinNode<E>* tmp)//获得二叉树的深度
    {

        if (BinTreeHeight(tmp) > 0) return BinTreeHeight(tmp) - 1;
        else return 0;

    }
    int  BinTreeNodes(BinNode<E>* tmp)//获得二叉树的结点数
    {

        if (tmp != NULL)
        {
            return (BinTreeNodes(tmp->left()) + BinTreeNodes(tmp->right()) + 1);
        }
        else return 0;

    }
    int  BinTreeHeight(BinNode<E>* tmp)//获得二叉树的高度
    {

        if (tmp == NULL)
        {
            return 0;
        }
        if (tmp->isLeaf())
        {
            return 1;
        }
        int lh = BinTreeHeight(tmp->left());
        int rh = BinTreeHeight(tmp->right());
        return 1 + (lh > rh ? lh : rh);

    }
    int  BinTreeLeafs(BinNode<E>* tmp)//获得二叉树的叶子结点数
    {

        if (tmp == NULL) return 0;
        if (tmp->isLeaf()) return 1;
        return BinTreeLeafs(tmp->left()) + BinTreeLeafs(tmp->right());

    }
    BinNode<E>*  find(BinNode<E>* tmp, E  e)//查找二叉树中是否含有某个名为e的结点
    {
        if (tmp == NULL) return NULL;
        if (tmp->getValue() == e) return tmp;
        if (find(tmp->left(), e) != NULL)
            return find(tmp->left(),e);
        else if (find(tmp->right(), e)!= NULL)
            return find(tmp->right(), e);
        else
            return NULL;
    }

    bool isPart(BinNode<E>* tmp1, BinNode<E>* tmp2) {
        if (tmp1 == NULL&&tmp2==NULL) return true;
        if (tmp1 == NULL&&tmp2!=NULL) return false;
        if (tmp1 != NULL && tmp2 == NULL) return false;
        return (isPart(tmp1->left(), tmp2->left()) && isPart(tmp1->right(), tmp2->right()))&&tmp1->getValue() == tmp2->getValue();
        //找值相同的根结点（遍历解决）
        //判断两结点是否包含（递归：值、左孩子、右孩子分别相同）
    }

public:
    BinTree()//默认构造函数
    {
        root = new  BinNode<E>;
    }
    ~BinTree()//析构函数
    {
        clear(root);
    }
    bool  BinTreeEmpty()//判断二叉树是否为空
    {
        if (root == NULL)
            return  true;
        else
            return  false;
    }
    BinNode<E>* getRoot()//获得根节点
    {
        return  root;
    }
    void  setRoot(BinNode<E>* r)//设置根节点
    {
        root = r;
    }
    //下面的函数是对外的函数，所以内部还会有一些同名的函数，但是参数列表不一样，实现数据的封装，外部的调用不会涉及到内部的数据对象
    void  clear()//清空二叉树
    {
        clear(root);
        root = NULL;
    }
    void  preOrder(void(*visit)(BinNode<E>* node))//先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        preOrder(root, visit);
    }
    void  inOrder(void(*visit)(BinNode<E>* node))  //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        inOrder(root, visit);
    }
    void  postOrder(void(*visit)(BinNode<E>* node))//先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        postOrder(root, visit);
    }
    void  LevelOrderTranverse(void(*visit)(BinNode<E>* node))//先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
    {
        LevelOrderTranverse(root, visit);
    }
    int  BinTreeDepth()//获得二叉树深度
    {
        return  BinTreeDepth(root);
    }
    int  BinTreeNodes()//获得二叉树结点数
    {
        return  BinTreeNodes(root);
    }
    int  BinTreeHeight()//获得二叉树高度
    {
        return  BinTreeHeight(root);
    }
    int  BinTreeLeafs()//获得二叉树叶子结点数
    {
        return  BinTreeLeafs(root);
    }
    BinNode<E>*  find(E  e)//查找二叉树中是否存在名为e的结点
    {
        return  find(root, e);
    }
    bool isPartTree(BinTree<E>* t1, BinTree<E>* t2) {
        E temp = t2->getRoot()->getValue();
        BinNode<E>* b=t1->find(temp);
        return isPart(b, t2->getRoot());
        }
};

template<typename  E>
void  printNode(BinNode<E>* tmp)
{
    cout << tmp->getValue() << "  ";
}

template<typename  E>
BinNode<E>* creatBinaryTree(string  s, int& x, int  n)
{
    if (s[x] == '#')
        return  NULL;
    else
    {
        BinNode<char>* node = new  BinNode<char>;
        x = x + 1;
        if (x < n)
        node->setLeft(creatBinaryTree<E>(s, x, n));
        x = x + 1;
        if (x < n)
        node->setRight(creatBinaryTree<E>(s, x, n));
        return  node;
    }
}

#endif