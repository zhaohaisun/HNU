#ifndef reliseADT 
#define reliseADT 
#include "ADT.h"
#include "string"
#include <iostream>
#include <queue>

template<typename  E>
class  BinTree :public binTree<E>//��������
{
private:
    BinNode<E>* root;//�����
    void  clear(BinNode<E>* r)//��ն�����
    {

        if (r == NULL) return;
        clear(r->left());
        clear(r->right());
        delete r;

    }
    void  preOrder(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
    {

        if (tmp != NULL) {
            visit(tmp);
            preOrder(tmp->left(), visit);
            preOrder(tmp->right(), visit);
        }

    }
    void  inOrder(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
    {

        if (tmp != NULL) {
            inOrder(tmp->left(), visit);
            visit(tmp);
            inOrder(tmp->right(), visit);
        }

    }
    void  postOrder(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
    {

        if (tmp != NULL) {
            postOrder(tmp->left(), visit);
            postOrder(tmp->right(), visit);
            visit(tmp);
        }

    }
    void  LevelOrderTranverse(BinNode<E>* tmp, void(*visit)(BinNode<E>* node))//��α�����void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
    {

        queue<BinNode<E>*> q;
        if (tmp != NULL) { q.push(tmp); }//ѹ���β
        BinNode<E>* b;
        while (!q.empty()) {
            b = q.front();//b���ڶ�ͷԪ��
            visit(b);
            q.pop();//������ͷԪ��
            if (b->left()) {
                q.push(b->left());//ѹ��b������
            }
            if (b->right()) {
                q.push(b->right());//ѹ��b���Һ���
            }
        }

    }
    int  BinTreeDepth(BinNode<E>* tmp)//��ö����������
    {

        if (BinTreeHeight(tmp) > 0) return BinTreeHeight(tmp) - 1;
        else return 0;

    }
    int  BinTreeNodes(BinNode<E>* tmp)//��ö������Ľ����
    {

        if (tmp != NULL)
        {
            return (BinTreeNodes(tmp->left()) + BinTreeNodes(tmp->right()) + 1);
        }
        else return 0;

    }
    int  BinTreeHeight(BinNode<E>* tmp)//��ö������ĸ߶�
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
    int  BinTreeLeafs(BinNode<E>* tmp)//��ö�������Ҷ�ӽ����
    {

        if (tmp == NULL) return 0;
        if (tmp->isLeaf()) return 1;
        return BinTreeLeafs(tmp->left()) + BinTreeLeafs(tmp->right());

    }
    BinNode<E>*  find(BinNode<E>* tmp, E  e)//���Ҷ��������Ƿ���ĳ����Ϊe�Ľ��
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
        //��ֵ��ͬ�ĸ���㣨���������
        //�ж�������Ƿ�������ݹ飺ֵ�����ӡ��Һ��ӷֱ���ͬ��
    }

public:
    BinTree()//Ĭ�Ϲ��캯��
    {
        root = new  BinNode<E>;
    }
    ~BinTree()//��������
    {
        clear(root);
    }
    bool  BinTreeEmpty()//�ж϶������Ƿ�Ϊ��
    {
        if (root == NULL)
            return  true;
        else
            return  false;
    }
    BinNode<E>* getRoot()//��ø��ڵ�
    {
        return  root;
    }
    void  setRoot(BinNode<E>* r)//���ø��ڵ�
    {
        root = r;
    }
    //����ĺ����Ƕ���ĺ����������ڲ�������һЩͬ���ĺ��������ǲ����б�һ����ʵ�����ݵķ�װ���ⲿ�ĵ��ò����漰���ڲ������ݶ���
    void  clear()//��ն�����
    {
        clear(root);
        root = NULL;
    }
    void  preOrder(void(*visit)(BinNode<E>* node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
    {
        preOrder(root, visit);
    }
    void  inOrder(void(*visit)(BinNode<E>* node))  //����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
    {
        inOrder(root, visit);
    }
    void  postOrder(void(*visit)(BinNode<E>* node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
    {
        postOrder(root, visit);
    }
    void  LevelOrderTranverse(void(*visit)(BinNode<E>* node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
    {
        LevelOrderTranverse(root, visit);
    }
    int  BinTreeDepth()//��ö��������
    {
        return  BinTreeDepth(root);
    }
    int  BinTreeNodes()//��ö����������
    {
        return  BinTreeNodes(root);
    }
    int  BinTreeHeight()//��ö������߶�
    {
        return  BinTreeHeight(root);
    }
    int  BinTreeLeafs()//��ö�����Ҷ�ӽ����
    {
        return  BinTreeLeafs(root);
    }
    BinNode<E>*  find(E  e)//���Ҷ��������Ƿ������Ϊe�Ľ��
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