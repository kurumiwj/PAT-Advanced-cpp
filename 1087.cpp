#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define INF 100000000
#define MAXN 210
using namespace std;

string destination="ROM";
int n,k,maxhappiness=0;
double maxaverage=0;
string start;
bool visit[MAXN];
int cost[MAXN][MAXN],happiness[MAXN],mincost[MAXN],totalroute[MAXN];
vector<int> path[MAXN],tmppath,path2;
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
					path[j].clear();
					path[j].push_back(u);
				}else{
					totalroute[j]+=totalroute[u];
					path[j].push_back(u);
				}
			}
		}
	}
}
void DFS(int index){
	if(index==0){
		tmppath.push_back(index);
		int tmpmaxhappiness=0;
		double tmpmaxaverage=0;
		for(int i=tmppath.size()-1;i>=0;i--){
			int id=tmppath[i];
			tmpmaxhappiness+=happiness[id];
		}
		if(tmpmaxhappiness>maxhappiness){
			maxhappiness=tmpmaxhappiness;
			maxaverage=maxhappiness*1.0/(tmppath.size()-1);
			path2=tmppath;
		}else if(tmpmaxhappiness==maxhappiness){
			tmpmaxaverage=maxhappiness*1.0/(tmppath.size()-1);
			if(tmpmaxaverage>maxaverage){
				maxaverage=tmpmaxaverage;
				path2=tmppath;
			}
		}
		tmppath.pop_back();
		return ;
	}
	tmppath.push_back(index);
	for(int i=0;i<path[index].size();i++){
		DFS(path[index][i]);
	}
	tmppath.pop_back();
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
	DFS(city[destination]);
	printf("%d %d %d %d\n",totalroute[city[destination]],mincost[city[destination]],maxhappiness,(int)maxaverage);
	for(int i=path2.size()-1;i>=0;i--){
		cout<<city2[path2[i]];
		if(i!=0) printf("->");
	}
	system("pause");
	return 0;
}