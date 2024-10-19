#include<bits/stdc++.h>
using namespace std;

using std::swap;
using std::fill;
using std::max;

const int MAXN=1001;
const int INF = -1000000000;
int G[MAXN][MAXN]={};
int edge[MAXN][MAXN]={};
int dp[MAXN]={};
int n;

int DP(int id){//id指的是作为起点的原点
if(dp[id]>0) return dp[id];//递归实现 
for(int i=0;i<n;i++){
	if(G[id][i]!=0) 
	dp[id]=max(dp[id],DP(i)+G[id][i]);//状态转移方程 
} 
return dp[id];
}

int main(){
	int n,m;
	cin>>m;
	while(m--){
	memset(G, 0, sizeof(G));//初始化
    fill(dp, dp + MAXN, 0);
		cin>>n;
		int a,b=0,maxIndex;
		for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &edge[i][0], &edge[i][1]);

            if(edge[i][0] < edge[i][1]){//长的边靠前
                swap(edge[i][0], edge[i][1]);
            }

            if(edge[i][0] > a && edge[i][1] > b){//求最大的矩形，即源点
                a = edge[i][0];
                b = edge[i][1];
                maxIndex = i;
            }

            for (int j = 0; j < i; ++j)//构建有向图
            {
                if(edge[i][0] > edge[j][0] && edge[i][1] > edge[j][1]){//矩形i能嵌套矩形j
                    G[i][j] = 1;
                }else if(edge[i][0] < edge[j][0] && edge[i][1] < edge[j][1]){//矩形j能被矩形i嵌套
                    G[j][i] = 1;
                }
            }
        }
        int ans = DP(maxIndex);
       cout<<ans+1;//顶点数为最长路径长度（边数）+1
    }
	return 0;
}



