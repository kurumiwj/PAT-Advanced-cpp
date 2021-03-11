#include <iostream>
#include <vector>
using namespace std;

int n,m,l;
int favoriteColor[210],stripeColor[10010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&favoriteColor[i]);
	scanf("%d",&l);
	for(int i=1;i<=l;i++)
		scanf("%d",&stripeColor[i]);
	int dp[m+1][l+1];
	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int j=0;j<=l;j++)
		dp[0][j]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=l;j++){
			if(favoriteColor[i]==stripeColor[j]){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
			}else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	printf("%d",dp[m][l]);
	system("pause");
	return 0;
}