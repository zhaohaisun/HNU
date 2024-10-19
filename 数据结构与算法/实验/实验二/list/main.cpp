#include <iostream>
using namespace std;
#include "LList.h"
#include"list.h"

int main() {
    LList<int> a1,b1,a2,b2;
    int n=0,m=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a1.append(a);
        b1.append(b);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a2.append(a);
        b2.append(b);
    }
    int maxs=0;
    if(b1.length() ==0&&b2.length()!=0)
    {
        maxs=b2.getValue();
    }
    else if(b1.length() !=0&&b2.length()==0)
    {
        maxs=b1.getValue();
    }
    else if(b1.length() !=0&&b2.length()!=0)
    {
        maxs=max(b2.getValue(),b1.getValue());
    }

    LList<int> a3,b3;
    for(int i=maxs;i>=0;i--)
    {
        b3.append(i);
        a3.append(0);
    }

    for(int i=0;i<n;i++)
    {
        int p=a1.getValue();//加数的系数 
        int q=b1.getValue();//加数的次方数 
        int pos=maxs-q;
        a3.moveToPos(pos);
        int h=a3.remove()+p;
        a3.insert(h);
        a1.next();
        b1.next();
    }
    
    for(int i=0;i<m;i++)
    {
        int p=a2.getValue(); //p是对应指数的系数
        int q=b2.getValue(); //q是指数
        int pos=maxs-q; //pos为q这个指数在b3,a3上的位置
        a3.moveToPos(pos);
        int h=a3.remove()+p;
        a3.insert(h);
        a2.next();
        b2.next();
    }

    a3.moveToStart();
    b3.moveToStart();

    for(int i=0;i<=maxs;i++)
    {

        int p=a3.getValue();
        int q=b3.getValue();
        if(p!=0){cout<<p<<" "<<q<<endl;}
        a3.next();
        b3.next();
     }

    return 0;
}

