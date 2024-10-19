#include <bits/stdc++.h>
using namespace std;
  
struct Item
{
    float weight;//��Ʒ���� 
    int value;//��Ʒ��ֵ 
};
  
//�洢��Ϣ�Ľ�� 
struct Node
{
    //level���㼶������ָʾװ���ĸ���Ʒ 
	//profit��Ŀǰװ��ļ�ֵ 
	//bound���Ըýڵ�Ϊ���������ܴﵽ�ļ�ֵ�Ͻ�
    int level, profit, bound;
    //Ŀǰװ��������� 
	float weight;
};
  

bool cmp(Item a, Item b)//��λ��ֵ���� 
{
    double r1 = (double)a.value / a.weight;//��λ��ֵ
    double r2 = (double)b.value / b.weight;
    return r1 > r2;//�������� 
}
  
//������uΪ���������е�����߽硣
//��Ҫʹ��̰���㷨��Ѱ��������������ֵ��
int bound(Node u, int n, int W, Item arr[])
{
    //�������Ʒ�������ڱ�������������0 
    if (u.weight >= W)
        return 0;
  
    //ͨ����ǰ�����ʼ������Ľ��� 
    int profit_bound = u.profit;
  
    //j�ܱȵ�ǰ�㼶��1 
    int j = u.level + 1;
    int totweight = u.weight;

    // whileѭ��������Ʒ����С��n���ۼ�����С�������� 
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
  
    //���k����n����������һ��Ĳ�������Ϊ���������ֵ
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value/arr[j].weight;
    return profit_bound;
}
  
 
int knapsack(int W, Item arr[], int n)//����ֵ�Ǳ�������ΪWʱ�������ĺ���
{
    sort(arr, arr + n, cmp);//���յ�λ��ֵ���� 
    queue<Node> Q;//�������������
    Node u, v;
    u.level = -1; //��ʼʱ�Ŀսڵ� 
    u.profit = u.weight = 0;
    Q.push(u);
    int maxProfit = 0;//��һ�Ӿ���������ȡһ����Ʒ�����㱻��ȡ��Ʒ����������Ʒ�����󣬲����������������
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();//����
        if (u.level == -1)//����ǳ�ʼ��㣬�㼶��Ϊ0
            v.level = 0;
        if (u.level==n-1)//���u�Ѿ������㼶��������ѭ�� 
		    break; 
        v.level = u.level + 1;//���u�������㼶�������Ӳ㼶���������ӽڵ������
        v.weight = u.weight + arr[v.level].weight;//����ǰ��Ʒ�������ͼ�ֵ�ӵ���ǰ�㼶��������� 
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit)//����ۼ�����С��W�����������֮ǰ�����������maxprofit
            maxProfit = v.profit;
        v.bound = bound(v, n, W, arr);//��ȡ��������ޣ��Ծ����Ƿ�v��ӵ�Q��
        if (v.bound > maxProfit)//����߽�ֵ����������������
            Q.push(v);
        v.weight = u.weight;//�ظ�����������������Ӹ���Ʒ��������
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }
    return maxProfit;
}
  
int main()
{
    int W;   //�������� 
    cin>>W;
    int n;   //��Ʒ��Ŀ 
    cin>>n;
    Item* arr=new Item[n]; 
    for(int i=0;i<n;i++){
    	cin>>arr[i].weight>>arr[i].value;
	} 
    cout << knapsack(W, arr, n);
    return 0;
}


