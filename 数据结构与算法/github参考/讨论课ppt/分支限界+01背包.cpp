#include <bits/stdc++.h>
using namespace std;
  
struct Item
{
    float weight;//物品质量 
    int value;//物品价值 
};
  
//存储信息的结点 
struct Node
{
    //level：层级，用来指示装入哪个物品 
	//profit：目前装入的价值 
	//bound：以该节点为根的子树能达到的价值上界
    int level, profit, bound;
    //目前装入的总重量 
	float weight;
};
  

bool cmp(Item a, Item b)//单位价值排序 
{
    double r1 = (double)a.value / a.weight;//单位价值
    double r2 = (double)b.value / b.weight;
    return r1 > r2;//降序排列 
}
  
//返回以u为根的子树中的利润边界。
//主要使用贪心算法来寻找最大利润的上限值。
int bound(Node u, int n, int W, Item arr[])
{
    //如果该物品重量大于背包重量，返回0 
    if (u.weight >= W)
        return 0;
  
    //通过当前利润初始化利润的界限 
    int profit_bound = u.profit;
  
    //j总比当前层级多1 
    int j = u.level + 1;
    int totweight = u.weight;

    // while循环，当物品索引小于n且累计重量小于总重量 
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
  
    //如果k不是n，则包括最后一项的部分内容为利润的上限值
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value/arr[j].weight;
    return profit_bound;
}
  
 
int knapsack(int W, Item arr[], int n)//返回值是背包容量为W时最大利润的函数
{
    sort(arr, arr + n, cmp);//按照单位价值排序 
    queue<Node> Q;//建队来遍历结点
    Node u, v;
    u.level = -1; //开始时的空节点 
    u.profit = u.weight = 0;
    Q.push(u);
    int maxProfit = 0;//逐一从决策树中提取一个物品，计算被提取物品的所有子物品的利润，并继续保存最大利润
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();//出队
        if (u.level == -1)//如果是初始结点，层级设为0
            v.level = 0;
        if (u.level==n-1)//如果u已经是最大层级，则跳出循环 
		    break; 
        v.level = u.level + 1;//如果u不是最大层级，则增加层级，并计算子节点的利润。
        v.weight = u.weight + arr[v.level].weight;//将当前物品的重量和价值加到当前层级的树结点上 
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit)//如果累计重量小于W，且利润大于之前的利润，则更新maxprofit
            maxProfit = v.profit;
        v.bound = bound(v, n, W, arr);//获取利润的上限，以决定是否将v添加到Q中
        if (v.bound > maxProfit)//如果边界值大于最大利润，则入队
            Q.push(v);
        v.weight = u.weight;//重复上述操作，但不添加该物品到背包中
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }
    return maxProfit;
}
  
int main()
{
    int W;   //背包重量 
    cin>>W;
    int n;   //物品数目 
    cin>>n;
    Item* arr=new Item[n]; 
    for(int i=0;i<n;i++){
    	cin>>arr[i].weight>>arr[i].value;
	} 
    cout << knapsack(W, arr, n);
    return 0;
}


