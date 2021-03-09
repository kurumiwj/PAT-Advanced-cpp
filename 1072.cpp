#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAXN 1020
#define INF 100000000
using namespace std;

int n,m,k,ds;
bool visit[MAXN];
int road[MAXN][MAXN],dis[MAXN][MAXN];
double average[MAXN];
vector<int> path[MAXN];
void init(){
	fill(visit+1,visit+n+m+1,false);
	for(int i=1;i<=n+m;i++)
		fill(road[i]+1,road[i]+n+m+1,INF);
	for(int i=n+1;i<=n+m;i++)
		fill(dis[i]+1,dis[i]+n+m+1,INF);
}
void Dijkstra(int index){
	fill(visit+1,visit+n+m+1,false);
	dis[index][index]=0;
	for(int i=1;i<=m+n;i++){
		int u=-1,min=INF;
		for(int j=1;j<=m+n;j++)
			if(!visit[j]&&dis[index][j]<min)
				u=j,min=dis[index][j];
		if(u==-1) return ;
		visit[u]=true;
		for(int j=1;j<=m+n;j++){
			if(!visit[j]&&road[u][j]<INF&&dis[index][u]+road[u][j]<=dis[index][j]){
				if(dis[index][u]+road[u][j]<dis[index][j]){
					dis[index][j]=dis[index][u]+road[u][j];
					path[j].clear();
					path[j].push_back(u);
				}else{
					path[j].push_back(u);
				}
			}
		}
	}
}
void ave(int index){
	double sum=0;
	for(int i=1;i<=n;i++)
		sum+=dis[index][i];
	average[index]=sum/n;
}
int string_to_int(string a){
	int toint;
	if(a[0]!='G') toint=stoi(a);
	else{
		toint=n+stoi(a.substr(1,a.length()-1));
	}
	return toint;
}
int main(){
	int h1,h2,length,minDis=-1,target=0;
	string house1,house2;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	init();
	for(int i=0;i<k;i++){	//前n个存放住户，后n+m个存放加油站
		cin>>house1>>house2;
		h1=string_to_int(house1);
		h2=string_to_int(house2);
		scanf("%d",&length);
		road[h1][h2]=length;
		road[h2][h1]=length;
	}
	for(int i=n+1;i<=n+m;i++){
		Dijkstra(i);
		ave(i);
		int tmpDis=INF;
		bool canBuilt=true;
		for(int j=1;j<=n;j++){
			if(dis[i][j]>ds){
				canBuilt=false;
				break;
			}
			if(dis[i][j]<tmpDis) tmpDis=dis[i][j];
		}
		if(canBuilt){
			if(tmpDis>minDis) minDis=tmpDis,target=i;
			else if(tmpDis==minDis){
				if(average[i]<average[target]){
					target=i;
				}else if(average[i]==average[target]){
					if(i<target) target=i;
				}
			}
		}
		// for(int j=1;j<=n;j++)
		// 	printf("%d ",dis[i][j]);
		// printf("\n");
	}
	if(minDis==-1) printf("No Solution");
	else{
		printf("G%d\n",target-n);
		printf("%.1f %.1f",(double)minDis,average[target]);
	}
	system("pause");
	return 0;
}