#include <bits/stdc++.h>
using namespace std;

// ��������������ȼ�
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
    stack<int> numStack;  // ������ֵ�ջ
    stack<char> opStack;  // ����������ջ
    
    for(int i=0;i<s.length();i++)//���Ϸ�������� 
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
            // �������֣��������������ַ�ת��Ϊ����
            int num = 0, j = i;
            while (j < s.size() && isdigit(s[j])) 
			{
                num = num * 10 + s[j] - '0';
                j++;
            }
            numStack.push(num);
            i = j - 1;  // ���� i ��ֵ
        } 
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
		{
            // ���������
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
            // ������ֱ����ջ
            opStack.push(s[i]);
        } 
		else if (s[i] == ')') 
		{
            // ���������ţ��������ڵı��ʽ�������
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
            opStack.pop();  // �������ų�ջ
        }
    }

    if (!opStack.empty()) 
	{
        // ����ջ��ʣ��������
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

