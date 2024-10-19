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

int DP(int id){//idָ������Ϊ����ԭ��
if(dp[id]>0) return dp[id];//�ݹ�ʵ�� 
for(int i=0;i<n;i++){
	if(G[id][i]!=0) 
	dp[id]=max(dp[id],DP(i)+G[id][i]);//״̬ת�Ʒ��� 
} 
return dp[id];
}

int main(){
	int n,m;
	cin>>m;
	while(m--){
	memset(G, 0, sizeof(G));//��ʼ��
    fill(dp, dp + MAXN, 0);
		cin>>n;
		int a,b=0,maxIndex;
		for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &edge[i][0], &edge[i][1]);

            if(edge[i][0] < edge[i][1]){//���ı߿�ǰ
                swap(edge[i][0], edge[i][1]);
            }

            if(edge[i][0] > a && edge[i][1] > b){//�����ľ��Σ���Դ��
                a = edge[i][0];
                b = edge[i][1];
                maxIndex = i;
            }

            for (int j = 0; j < i; ++j)//��������ͼ
            {
                if(edge[i][0] > edge[j][0] && edge[i][1] > edge[j][1]){//����i��Ƕ�׾���j
                    G[i][j] = 1;
                }else if(edge[i][0] < edge[j][0] && edge[i][1] < edge[j][1]){//����j�ܱ�����iǶ��
                    G[j][i] = 1;
                }
            }
        }
        int ans = DP(maxIndex);
       cout<<ans+1;//������Ϊ�·�����ȣ�������+1
    }
	return 0;
}



