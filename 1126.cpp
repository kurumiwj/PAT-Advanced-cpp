#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#define MAXN 505
using namespace std;

int n;
int edge[MAXN][MAXN];
bool visit[MAXN];
void DFS(int index){
	if(visit[index]) return ;
	visit[index]=true;
	for(int i=1;i<=n;i++)
		if(edge[index][i]>0&&!visit[i])
			DFS(i);
}
bool isConnected(){
	bool flag=true;
	for(int i=1;i<=n;i++)
		if(!visit[i]) flag=false;
	return flag;
}
int main(){
	int m,v1,v2;
	scanf("%d%d",&n,&m);
	int degree[n+1];
	for(int i=1;i<=n;i++){
		fill(edge[i],edge[i]+n+1,0);
		fill(degree,degree+n+1,0);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		edge[v1][v2]=edge[v2][v1]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(edge[i][j]>0) degree[i]++;
		}
	}
	DFS(1);
	int oddcnt=0;
	for(int i=1;i<=n;i++){
		if(i!=1) printf(" ");
		printf("%d",degree[i]);
		if(degree[i]%2!=0){
			oddcnt++;
		}
	}
	printf("\n");
	if(!isConnected()){
		printf("Non-Eulerian");
	}else{
		if(oddcnt==0) printf("Eulerian");
		else if(oddcnt==2) printf("Semi-Eulerian");
		else printf("Non-Eulerian");
	}
	system("pause");
	return 0;
}
