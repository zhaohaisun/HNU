#include <bits/stdc++.h>
using namespace std;

map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}, {')', 0}};
stack<int> Stack;
stack<char> Stack1;
char ch, chr;
int num1, num2;

int main() {
	cin >> ch;
	while (ch != '#') {
		if (ch >= '0' && ch <= '9') {
			int num = ch - '0';
			cin >> ch;
			while (ch >= '0' && ch <= '9') {
				num = num * 10 + ch - '0';
				cin >> ch;
			}
			Stack.push(num);
		} else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			if (Stack1.empty() || priority[ch] > priority[Stack1.top()]) {
				Stack1.push(ch);
				cin >> ch;
			} else {
				num2 = Stack.top();
				Stack.pop();
				num1 = Stack.top();
				Stack.pop();
				chr = Stack1.top();
				Stack1.pop();
				switch (chr) {
					case '+':
						Stack.push(num1 + num2);
						break;
					case '-':
						Stack.push(num1 - num2);
						break;
					case '*':
						Stack.push(num1 * num2);
						break;
					case '/':
						if (num2 == 0) {
							printf("NO");
							return 0;
						}
						Stack.push(num1 / num2);
						break;
				}
			}
		} else if (ch == '(') {
			Stack1.push(ch);
			cin >> ch;
		} else if (ch == ')') {
			while (Stack1.top() != '(') {
				num2 = Stack.top();
				Stack.pop();
				num1 = Stack.top();
				Stack.pop();
				chr = Stack1.top();
				Stack1.pop();
				switch (chr) {
					case '+':
						Stack.push(num1 + num2);
						break;
					case '-':
						Stack.push(num1 - num2);
						break;
					case '*':
						Stack.push(num1 * num2);
						break;
					case '/':
						if (num2 == 0) {
							printf("NO");
							return 0;
						}
						Stack.push(num1 / num2);
						break;
				}
			}
			Stack1.pop();
			cin >> ch;
		} else {
			printf("NO");
			return 0;
		}
	}
	while (!Stack1.empty()) {
		num2 = Stack.top();
		Stack.pop();
		num1 = Stack.top();
		Stack.pop();
		chr = Stack1.top();
		Stack1.pop();
		switch (chr) {
			case '+':
				Stack.push(num1 + num2);
				break;
			case '-':
				Stack.push(num1 - num2);
				break;
			case '*':
				Stack.push(num1 * num2);
				break;
			case '/':
				if (num2 == 0) {
					printf("NO");
					return 0;
				}
				Stack.push(num1 / num2);
				break;
		}
	}
	printf("%d\n", Stack.top());
	return 0;
}

