#ifndef exp_4
#define exp_4

template<typename E> class BinNode { //�����
	private:
		BinNode *lc; //����
		BinNode *rc; //�Һ���
		E elem;
	public:
		BinNode() { //Ĭ�Ϲ��캯�����������Һ���Ϊ��
			this->lc = this->rc = NULL;
		}
		BinNode(E tmp, BinNode *l = NULL, BinNode *r = NULL) { //���ι��캯��
			this->elem = tmp;
			this->lc = l;
			this->rc = r;
		}
		BinNode *left() { //��������
			return this->lc;
		}
		BinNode *right() { //�����Һ���
			return this->rc;
		}
		void setLeft(BinNode *l) { //��������
			lc = (BinNode *)l;
		}
		void setRight(BinNode *r) { //�����Һ���
			rc = (BinNode *)r;
		}
		void setValue(E tmp) { //���õ�ǰ����ֵ
			this->elem = tmp;
		}
		E getValue() { //��õ�ǰ����ֵ
			return this->elem;
		}
		bool isLeaf() { //�жϵ�ǰ����Ƿ�ΪҶ�ӽ��
			return (rc == NULL) && (lc == NULL);
		}
};
#endif