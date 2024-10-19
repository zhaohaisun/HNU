#include <bits/stdc++.h>
using namespace std;

// 定义运算符的优先级
int priority(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() 
{
    string s;
    getline(cin, s, '#');
    stack<int> numStack;  // 存放数字的栈
    stack<char> opStack;  // 存放运算符的栈
    
    for(int i=0;i<s.length();i++)//不合法的运算符 
    {
    	if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')')
    	{
    		if(s[i]<'0'||s[i]>'9')
    		{
    			cout<<"NO";
    			return 0;
			}
		}
	}

    for(int i = 0;i < s.size();i++) 
	{
        if(isdigit(s[i])) 
		{
            // 处理数字，将连续的数字字符转化为数字
            int num = 0, j = i;
            while (j < s.size() && isdigit(s[j])) 
			{
                num = num * 10 + s[j] - '0';
                j++;
            }
            numStack.push(num);
            i = j - 1;  // 更新 i 的值
        } 
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
		{
            // 处理运算符
            while (!opStack.empty() && priority(opStack.top()) >= priority(s[i])) 
			{
                int b = numStack.top(); numStack.pop();
                int a = numStack.top(); numStack.pop();
                char op = opStack.top(); opStack.pop();
                int res;
                if (op == '+') res = a + b;
                else if (op == '-') res = a - b;
                else if (op == '*') res = a * b;
                else res = a / b;
                numStack.push(res);
            }
            opStack.push(s[i]);
        } 
		else if (s[i] == '(') 
		{
            // 左括号直接入栈
            opStack.push(s[i]);
        } 
		else if (s[i] == ')') 
		{
            // 处理右括号，将括号内的表达式计算出来
            while (opStack.top() != '(') 
			{
                int b = numStack.top(); numStack.pop();
                int a = numStack.top(); numStack.pop();
                char op = opStack.top(); opStack.pop();
                int res;
                if (op == '+') res = a + b;
                else if (op == '-') res = a - b;
                else if (op == '*') res = a * b;
                else res = a / b;
                numStack.push(res);
            }
            opStack.pop();  // 将左括号出栈
        }
    }

    if (!opStack.empty()) 
	{
        // 处理栈中剩余的运算符
        while (!opStack.empty()) 
		{
            int b = numStack.top(); numStack.pop();
            int a = numStack.top(); numStack.pop();
            char op = opStack.top(); opStack.pop();
            int res;
            if(op =='+') res = a + b;
			else if(op == '-') res = a - b;
			else if(op == '*') res = a * b;
			else res = a / b;
			numStack.push(res);
		}
	}
	cout << numStack.top() << endl;
	return 0;
}

