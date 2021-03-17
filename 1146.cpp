#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 1005
using namespace std;

int graph[MAXN][MAXN];
int main(){
	int n,m,v1,v2,k,tmp;
	bool flag;
	scanf("%d%d",&n,&m);
	vector<int> indegree(n+1,0),tmpindegree,ans;
	for(int i=1;i<=n;i++)
		fill(graph[i],graph[i]+n+1,0);
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		graph[v1][v2]=1;
		indegree[v2]++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		flag=true;
		tmpindegree=indegree;
		for(int j=0;j<n;j++){
			scanf("%d",&tmp);
			if(flag&&j!=n-1){
				if(tmpindegree[tmp]!=0){
					flag=false;
					ans.push_back(i);
				}else{
					for(int k=1;k<=n;k++){
						if(graph[tmp][k]>0) tmpindegree[k]--;
					}
				}
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}
	system("pause");
	return 0;
}
