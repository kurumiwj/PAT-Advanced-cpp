#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define INF 100000000
#define MAXN 210
using namespace std;

string destination="ROM";
int n,k;
string start;
bool visit[MAXN];
int cost[MAXN][MAXN],happiness[MAXN],mincost[MAXN],totalroute[MAXN],path[MAXN],maxhappiness[MAXN],totalcity[MAXN];
map<string,int> city;
map<int,string> city2;
void init(){
	for(int i=0;i<n;i++)
		fill(cost[i],cost[i]+n,INF);
	fill(visit,visit+n,false);
	fill(mincost,mincost+n,INF);
	fill(totalroute,totalroute+n,1);
}
void Dijkstra(int index){
	mincost[index]=0;
	for(int i=0;i<n;i++){
		int u=-1,min_cost=INF;
		for(int j=0;j<n;j++){
			if(!visit[j]&&min_cost>mincost[j]){
				u=j;
				min_cost=mincost[j];
			}
		}
		if(u==-1) return ;
		visit[u]=true;
		for(int j=0;j<n;j++){
			if(!visit[j]&&cost[u][j]<INF&&cost[u][j]+mincost[u]<=mincost[j]){
				if(cost[u][j]+mincost[u]<mincost[j]){
					totalroute[j]=totalroute[u];
					mincost[j]=cost[u][j]+mincost[u];
					maxhappiness[j]=maxhappiness[u]+happiness[j];
					totalcity[j]=totalcity[u]+1;
					path[j]=u;
				}else{
					totalroute[j]+=totalroute[u];
					if(maxhappiness[u]+happiness[j]>maxhappiness[j]){
						path[j]=u;
						totalcity[j]=totalcity[u]+1;
						maxhappiness[j]=maxhappiness[u]+happiness[j];
					}else if(maxhappiness[u]+happiness[j]==maxhappiness[j]){
						int tmpuaverage=maxhappiness[j]*1.0/(totalcity[u]+1);
						int tmpjaverage=maxhappiness[j]*1.0/totalcity[j];
						if(tmpjaverage<tmpuaverage){
							totalcity[j]=totalcity[u]+1;
							path[j]=u;
						}
					}
				}
			}
		}
	}
}
void print(int index){
	if(index==0){
		cout<<city2[index];
		return ;
	}
	print(path[index]);
	printf("->");
	cout<<city2[index];
}
int main(){
	string tmpcity1,tmpcity2;
	int tmphappiness,length;
	scanf("%d%d",&n,&k);
	init();
	cin>>start;
	city[start]=0;
	city2[0]=start;
	for(int i=1;i<n;i++){
		cin>>tmpcity1;
		scanf("%d",&tmphappiness);
		city[tmpcity1]=i;
		city2[i]=tmpcity1;
		happiness[i]=tmphappiness;
	}
	for(int i=0;i<k;i++){
		cin>>tmpcity1>>tmpcity2;
		scanf("%d",&length);
		cost[city[tmpcity1]][city[tmpcity2]]=length;
		cost[city[tmpcity2]][city[tmpcity1]]=length;
	}
	Dijkstra(0);
	int maxaverage=maxhappiness[city[destination]]/totalcity[city[destination]];
	printf("%d %d %d %d\n",totalroute[city[destination]],mincost[city[destination]],maxhappiness[city[destination]],maxaverage);
	print(city[destination]);
	system("pause");
	return 0;
}