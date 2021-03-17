#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAXN 202
using namespace std;

int nv,ne;
int graph[MAXN][MAXN];
bool visit[MAXN];
bool isClique(vector<int> q){
	for(int i=0;i<q.size()-1;i++)
		for(int j=i+1;j<q.size();j++){
			if(graph[q[i]][q[j]]==0) return false;
		}
	return true;
}
bool isMaxClique(vector<int> q){
	fill(visit+1,visit+nv+1,false);
	for(int i=0;i<q.size();i++) visit[q[i]]=true;
	for(int i=1;i<=nv;i++){
		if(!visit[i]){
			int j=0;
			for(j=0;j<q.size();j++){
				if(graph[i][q[j]]==0) break;
			}
			if(j==q.size()) return false;
		}
	}
	return true;
}
int main(){
	int v1,v2,m,tmp,sum;
	scanf("%d%d",&nv,&ne);
	for(int i=1;i<=nv;i++)
		fill(graph[i]+1,graph[i]+nv+1,0);
	for(int i=0;i<ne;i++){
		scanf("%d%d",&v1,&v2);
		graph[v1][v2]=graph[v2][v1]=1;
	}
	scanf("%d",&m);
	vector<int> query[m];
	for(int i=0;i<m;i++){
		scanf("%d",&sum);
		for(int j=0;j<sum;j++){
			scanf("%d",&tmp);
			query[i].push_back(tmp);
		}
		if(isClique(query[i])){
			if(isMaxClique(query[i])) printf("Yes\n");
			else printf("Not Maximal\n");
		}else
			printf("Not a Clique\n");
	}
	system("pause");
	return 0;
}
