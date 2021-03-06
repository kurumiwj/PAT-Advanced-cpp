/*
4 4 0 2
1 2 2 3
0 1 1
0 3 1
1 2 1
3 2 1
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000
#define MAXN 501
using namespace std;

int n,m;
int road[MAXN][MAXN];
int dis[MAXN],rescue[MAXN],maxrescue[MAXN],num[MAXN];
bool visit[MAXN]={false};
void init(){
	for(int i=0;i<n;i++){
		fill(road[i],road[i]+n,INF);
	}
	fill(visit,visit+n,false);
	fill(dis,dis+n,INF);
}
void Dijkstra(int start){
	dis[start]=0;
	num[start]=1;
	maxrescue[start]=rescue[start];
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(!visit[j]&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) return ;
		visit[u]=true;
		for(int j=0;j<n;j++){
			if(!visit[j]&&road[u][j]<INF&&road[u][j]+dis[u]<=dis[j]){	//路径更新
				if(road[u][j]+dis[u]==dis[j]){	//最短路径相同时比较救援队数量
					num[j]+=num[u];
					if(maxrescue[u]+rescue[j]>maxrescue[j]) maxrescue[j]=maxrescue[u]+rescue[j];
				}
				else{	//最短路径更短时更新路径
					num[j]=num[u];
					dis[j]=road[u][j]+dis[u];
					maxrescue[j]=maxrescue[u]+rescue[j];
				}
				
			}
		}
	}
}
int main(){
	int start,end,tmp,city1,city2,length;
	scanf("%d%d%d%d",&n,&m,&start,&end);
	init();
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		rescue[i]=tmp;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&city1,&city2,&length);
		road[city1][city2]=road[city2][city1]=length;
	}
	Dijkstra(start);
	printf("%d %d",num[end],maxrescue[end]);
	system("pause");
	return 0;
}