#include <iostream>
#include "llist.h"
#include "relise_llist.h"
#include <cstring>
using namespace std;

int main() {
	string str;
	cin >> str;
	LList<char> a;
	LList<char> b;
 	for (int i = 0; i < str.size(); i++) {
		a.append(str[i]);
	}
	for (int i = str.size() - 1; i >= 0; i--) {
		b.append(str[i]);
	}
	for (int i = 0; i < str.size(); i++) {
		if (a.getValue() == b.getValue()) {
			cout << "yes" << endl;
			return 0;
		}
		else {
			cout << "no" << endl;
			return 0;
		}
	}
	return 0;
}
