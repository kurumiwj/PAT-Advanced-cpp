#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 510
#define INF 100000000
using namespace std;

int n,m,start,destination;
bool visit[MAXN]={false};
int dis[MAXN],road[MAXN][MAXN],path[MAXN],cost[MAXN][MAXN],mincost[MAXN];
void init(){
	fill(dis,dis+n,INF);
	fill(visit,visit+n,false);
	fill(path,path+n,0);
	fill(mincost,mincost+n,INF);
	for(int i=0;i<n;i++)
		fill(road[i],road[i]+n,INF);
}
void Dijkstra(int start){
	dis[start]=0;
	mincost[start]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(!visit[j]&&dis[j]<min)
				u=j,min=dis[j];
		}
		if(u==-1) return ;
		visit[u]=true;
		for(int j=0;j<n;j++){
			if(!visit[j]&&road[u][j]<INF&&dis[u]+road[u][j]<=dis[j]){
				if(dis[u]+road[u][j]<dis[j]){	//有更短路径
					dis[j]=dis[u]+road[u][j];
					mincost[j]=mincost[u]+cost[u][j];
					path[j]=u;
				}else{
					if(mincost[j]>mincost[u]+cost[u][j]){
						mincost[j]=mincost[u]+cost[u][j];
						path[j]=u;
					}
				}
			}
		}
	}
}
void DFS(int index){
	if(index==start){
		printf("%d ",index);
		return ;
	}
	DFS(path[index]);
	printf("%d ",index);
}
int main(){
	int city1,city2,length,tmpcost;
	scanf("%d%d%d%d",&n,&m,&start,&destination);
	init();
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&city1,&city2,&length,&tmpcost);
		road[city1][city2]=road[city2][city1]=length;
		cost[city1][city2]=cost[city2][city1]=tmpcost;
	}
	Dijkstra(start);
	DFS(destination);
	printf("%d %d",dis[destination],mincost[destination]);
	system("pause");
	return 0;
}