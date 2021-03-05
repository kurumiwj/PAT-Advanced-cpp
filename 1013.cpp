/*
4 4 4
1 2
1 4
2 3
3 4
1 2 3 4
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1001
using namespace std;

int n,m,k,cnt=0;
int highway[MAXN][MAXN];
bool visit[MAXN]={false};
void DFS(int index){
	if(visit[index]==true) return ;
	visit[index]=true;
	for(int i=1;i<=n;i++){
		if(highway[index][i]>0&&!visit[i]) DFS(i);
	}
}
void DFSTraversal(int lost){
	visit[lost]=true;	//该城市已经沦陷，与之相连的所有公路全部断掉
	for(int i=1;i<=n;i++){
		if(i!=lost&&!visit[i]){	//当前访问的不是沦陷城市并且还未访问过
			visit[i]=true;
			for(int j=1;j<=n;j++){
				if(highway[i][j]>0&&!visit[j]&&j!=lost) DFS(j);	//若从i到j有公路且j未访问过并且j未沦陷
			}
			cnt++;
		}
	}
}
int main(){
	int city1,city2;
	scanf("%d%d%d",&n,&m,&k);
	int query[k];
	for(int i=0;i<m;i++){
		scanf("%d%d",&city1,&city2);
		highway[city1][city2]=1;
		highway[city2][city1]=1;
	}
	for(int i=0;i<k;i++) scanf("%d",&query[i]);
	for(int i=0;i<k;i++){
		cnt=0;
		fill(visit,visit+MAXN,false);
		DFSTraversal(query[i]);
		printf("%d\n",cnt==0?0:cnt-1);
	}
	system("pause");
	return 0;
}