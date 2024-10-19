#include <iostream>
#include "reliseADT.h"

string s;
int len,a,b = 0;

int main() {
	BinTree<char>* BT1 = new BinTree<char>;
	getline(cin, s);
	BT1->setRoot(creatBinaryTree<char>(s, a, s.size()));
	BinTree<char>* BT2 = new BinTree<char>;
	getline(cin, s);
	BT2->setRoot(creatBinaryTree<char>(s, b, s.size()));
	if (BT1->isPartTree(BT1, BT2))
		cout << "yes";
	else
		cout << "no";
}