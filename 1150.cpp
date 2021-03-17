#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 202
#define INF 99999999
using namespace std;

int n,m;
int graph[MAXN][MAXN];
int main(){
	int city1,city2,dist,k,mindist=INF,index;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fill(graph[i]+1,graph[i]+n+1,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&city1,&city2,&dist);
		graph[city1][city2]=graph[city2][city1]=dist;
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		bool flag=true;
		int visit[n+1]={0};
		int sum,cnt=0,start,now,next,distance=0;
		scanf("%d",&sum);
		scanf("%d",&start);
		visit[start]++,cnt++;
		now=start;
		for(int j=1;j<sum;j++){
			scanf("%d",&next);
			if(flag){
				if(graph[now][next]==INF){	//两个城市之间没有路，之后的数据都不用再考虑了
					flag=false;
				}else{
					if(visit[next]==0) cnt++;
					visit[next]++;
					distance+=graph[now][next];
					now=next;
				}
			}
		}
		//结束循环后next即为终点
		if(flag==false){
			printf("Path %d: NA (Not a TS cycle)\n",i);
			continue;
		}else if(cnt!=n||start!=next){	//未访问所有顶点或者起终点不一样
			printf("Path %d: %d (Not a TS cycle)\n",i,distance);
			continue;
		}
		flag=true;
		if(mindist>distance){
			mindist=distance;
			index=i;
		}
		for(int j=1;j<=n;j++){
			if(j!=start&&j!=next&&visit[j]>1||visit[j]>2){	//除了起终点以外有别的点访问超过1次或者有的顶点访问超过2次
				flag=false;
				printf("Path %d: %d (TS cycle)\n",i,distance);
				break;
			}
		}
		if(flag) printf("Path %d: %d (TS simple cycle)\n",i,distance);
	}
	printf("Shortest Dist(%d) = %d",index,mindist);
	system("pause");
	return 0;
}
