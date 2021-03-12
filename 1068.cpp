#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int coin[n+1];
	bool path[n+1][m+1];
	for(int i=1;i<=n;i++)
		scanf("%d",&coin[i]);
	sort(coin+1,coin+n+1,cmp);
	int dp[10010];
	for(int i=0;i<=n;i++)
		fill(path[i],path[i]+m+1,false);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=coin[i];j--){
			if(dp[j]<=dp[j-coin[i]]+coin[i]){
				path[i][j]=true;
				dp[j]=dp[j-coin[i]]+coin[i];
			}
		}
	}
	if(dp[m]!=m) printf("No Solution");
	else{
		vector<int> path2;
		int index=n,volume=m;
		while(volume>0){
			if(path[index][volume]){
				path2.push_back(index);
				volume-=coin[index];
			}
			index--;
		}
		for(int i=0;i<path2.size();i++){
			if(i!=0) printf(" ");
			printf("%d",coin[path2[i]]);
		}
	}
	system("pause");
	return 0;
}