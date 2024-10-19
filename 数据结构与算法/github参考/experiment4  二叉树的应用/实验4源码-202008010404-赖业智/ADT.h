#ifndef ADT 
#define ADT 
#include<iostream>
#include"string"
#include<queue>
using  namespace  std;

template<typename  E>
class  BinNode//�����
{
private:
    BinNode* lc;//����
    BinNode* rc;//�Һ���
    E  elem;
public:
    BinNode()//Ĭ�Ϲ��캯�����������Һ���Ϊ��
    {
        lc = NULL;
        rc = NULL;


    }
    BinNode(E  tmp, BinNode* l = NULL, BinNode* r = NULL)//���ι��캯��
    {
        elem = tmp;
        lc = l;
        rc = r;


    }
    BinNode* left()//��������
    {
        return lc;



    }
    BinNode* right()//�����Һ���
    {

        return rc;


    }
    void  setLeft(BinNode* l)//��������
    {
        lc = l;


    }
    void  setRight(BinNode* r)//�����Һ���
    {
        rc = r;

    }
    void  setValue(E  tmp)//���õ�ǰ����ֵ
    {
        elem = tmp;


    }
    E  getValue()//��õ�ǰ����ֵ
    {
        return elem;

    }
    bool  isLeaf()//�жϵ�ǰ����Ƿ�ΪҶ�ӽ��
    {
        if (lc == NULL && rc == NULL)return true;
        return false;
    }
};


template<typename E>
class binTree
{

public:
    binTree()
    {
    }
    ~binTree()
    {
    }
    virtual bool BinTreeEmpty() = 0;
    virtual BinNode<E>* getRoot() = 0;
    virtual void setRoot(BinNode<E>* r) = 0;
    virtual void clear() = 0;
    virtual void preOrder(void(*visit)(BinNode<E>* node)) = 0;
    virtual void inOrder(void(*visit)(BinNode<E>* node)) = 0;
    virtual void postOrder(void(*visit)(BinNode<E>* node)) = 0;
    virtual void LevelOrderTranverse(void(*visit)(BinNode<E>* node)) = 0;
    virtual int BinTreeDepth() = 0;
    virtual int BinTreeNodes() = 0;
    virtual int BinTreeHeight() = 0;
    virtual int BinTreeLeafs() = 0;
};

#endif 