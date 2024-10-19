#ifndef exp_4
#define exp_4

template<typename E> class BinNode { //结点类
	private:
		BinNode *lc; //左孩子
		BinNode *rc; //右孩子
		E elem;
	public:
		BinNode() { //默认构造函数，设置左右孩子为空
			this->lc = this->rc = NULL;
		}
		BinNode(E tmp, BinNode *l = NULL, BinNode *r = NULL) { //带参构造函数
			this->elem = tmp;
			this->lc = l;
			this->rc = r;
		}
		BinNode *left() { //返回左孩子
			return this->lc;
		}
		BinNode *right() { //返回右孩子
			return this->rc;
		}
		void setLeft(BinNode *l) { //设置左孩子
			lc = (BinNode *)l;
		}
		void setRight(BinNode *r) { //设置右孩子
			rc = (BinNode *)r;
		}
		void setValue(E tmp) { //设置当前结点的值
			this->elem = tmp;
		}
		E getValue() { //获得当前结点的值
			return this->elem;
		}
		bool isLeaf() { //判断当前结点是否为叶子结点
			return (rc == NULL) && (lc == NULL);
		}
};
#endif