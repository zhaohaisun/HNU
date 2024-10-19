#include <iostream>
using namespace std;
#include <cstring>
#include <math.h>
#define NoEdge -1

int n;//����ͼ�Ķ������
int a[101][101];//����ͼ���ڽӾ���
int x[101];//���嵱ǰ��
int bestx[101];//���嵱ǰ���Ž�
int bestc;//���嵱ǰ��ǰֵ
int cc;//���嵱ǰ·�����ȣ��γɻ���ʱ����bestc�ȽϿ��ܲ��ܸ���bestc
void getmincost(int i) {
	//������ʵ�n���ڵ�,Ҫ�ж��Ƿ��γɻ�·
	//�����ǰֵ��������ֵ����������ֵ�����Ž�
	if (i == n) {
		//�γɻ�·����������x[n-1]��x[n]��ͨ��x[n]��x[1]��ͨ
		if (a[x[n - 1]][x[n]] != NoEdge && a[x[n]][1] != NoEdge) { //˵���γ��˻�·
			//�����ǰֵ��������ֵ����������ֵ�����Ž�
			//bestc=NoEdge˵����û�й��ѵ�һ����·���Ǿ����������һ�����н�
			if (cc + a[x[n - 1]][x[n]] + a[x[n]][1] < bestc || bestc == NoEdge) {
				for (int k = 2; k <= n; k++)
					bestx[k] = x[k];
				bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][1]; //��������ֵ
			}
		}
		return ;
	}
	//��ǰ�ڵ�i�㣬���ü���Ѱ��
	else {
		for (int j = i; j <= n; j++) {
			//�ж��Ƿ���Խ���x[j]����
			//x[i-1]��x[j]��ͨʹ��1-i������һ��·�����ۼƻ�������Ŀǰ����ֵ
			//���Խ���x[j]����
			//����Ҫ���ľ��ǽ���x[i]��x[j],����i+1��
			//˼��������n��ȫ�������⣬�ݹ����
			//bestc=NoEdge˵����û�й��ѵ�һ����·���Ǿ����������һ�����н�
			//���ڵĽ���x[1],x[2]...x[i]...x[j]...x[n]
			if ((a[x[i - 1]][x[j]] != NoEdge && cc + a[x[i - 1]][x[j]] < bestc) || bestc == NoEdge) {
				//�������������Խ���
				//����֮�����ڵĽ���x[1],x[2]...x[j]...x[i]...x[n]
				swap(x[i], x[j]);
				//���ڵĽ���x[1],x[2]...x[j]...x[i]...x[n]
				//��ʱ��i��Ԫ����==x[j]
				//��j��Ԫ����==x[i]
				cc = cc + a[x[i - 1]][x[i]]; //����·���ĳ��ȣ�����i+1��
				getmincost(i + 1);
				cc = cc - a[x[i - 1]][x[i]]; //��ԭ·���ĳ��ȣ��Ƚ�x[j+1]����

				swap(x[i], x[j]); //��ԭ֮ǰ�Ľ�
				//���ڵĽ���x[1],x[2]...x[i]...x[j]...x[n]
			}
		}
	}
	return ;

}

int main() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			a[i][j] = 0;
	}
	cin >> n; //���붥�����
	int k;
	memset(a, NoEdge, sizeof(a));
	cin >> k; //����ߵĸ���;
	int p, q, len;
	//��ʼ���ڽӾ���
	for (int i = 1; i <= k; i++) {
		cin >> p >> q >> len;
		p++;
		q++;
		a[p][q] = a[q][p] = len;
	}
	//��ʼ�����Ž�
	for (int i = 1; i <= n; i++)
		bestx[i] = x[i] = i;
	//��ʼ������ֵ
	bestc = NoEdge;
	cc = 0; //��ʼ����ǰֵΪ0
	getmincost(2);//��������֪
	bool flat = true;
	for (int i = 1; i < n; i++) {
		if (a[bestx[i]][bestx[i + 1]] == 0) {
			cout << -1 << endl;
			flat = false;
			break;
		}
	}
	
	if (flat) {
		cout << bestc << endl;
		for (int i = 1; i <= n; i++)
			cout << bestx[i] - 1 << " ";
		cout << 0;
	}
	return 0;
}

