#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>
#define MAXN 10010
using namespace std;

int father[MAXN];
bool hashTable[MAXN],visit[MAXN];
void init(){
	for(int i=0;i<MAXN;i++)
		father[i]=i;
}
int find(int x){
	int v=x;
	while(x!=father[x]) x=father[x];
	while(v!=father[v]){
		father[v]=x;
		v=father[v];
	}
	return x;
}
void Union(int a,int b){
	int faA=find(a);
	int faB=find(b);
	if(faA<=faB) father[faB]=faA;
	else father[faA]=faB;
}
int main(){
	int n,sum,trees=0,tmp,cnt=0;
	init();
	scanf("%d",&n);
	vector<int> indices[n+1];
	for(int i=0;i<n;i++){
		scanf("%d",&sum);
		for(int j=0;j<sum;j++){
			scanf("%d",&tmp);
			indices[i].push_back(tmp);
			if(hashTable[tmp]==false){
				cnt++;
				hashTable[tmp]=true;
			}
		}
		for(int j=1;j<sum;j++){	//更新，防止有的鸟是同一颗树上的但是根不同导致trees出错
			Union(indices[i][j-1],indices[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<indices[i].size();j++){
			int root=find(indices[i][j]);
			if(!visit[root]){
				trees++;	//找到一个未访问过的连通块
				visit[root]=true;
				break;
			}
		}
	}
	printf("%d %d\n",trees,cnt);
	int q,bird1,bird2;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&bird1,&bird2);
		if(father[bird1]==father[bird2]) printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}