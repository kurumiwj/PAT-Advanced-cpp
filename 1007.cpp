/*
6
-2 11 -4 13 -5 -2
 */
#include <iostream>
using namespace std;

int main(){
	int k,max;
	scanf("%d",&k);
	bool ispositive=false;
	int dp[k],start[k],a[k];
	for(int i=0;i<k;i++){
		scanf("%d",&a[i]);
		if(a[i]>=0) ispositive=true;
	}
	if(ispositive){
		dp[0]=a[0];
		start[0]=0;
		for(int i=1;i<k;i++){	//若前i-1个最大子列和加上第i个数没有第i个数大则更新前n个最大子列和为第i个数本身
			if(dp[i-1]+a[i]<=a[i]){
				start[i]=i;
				dp[i]=a[i];
			}else{
				start[i]=start[i-1];
				dp[i]=dp[i-1]+a[i];
			}
		}
		max=0;
		for(int i=1;i<k;i++){
			if(dp[max]<dp[i]) max=i;
		}
		printf("%d %d %d",dp[max],a[start[max]],a[max]);
	}else{
		printf("0 %d %d",a[0],a[k-1]);
	}
	system("pause");
	return 0;
}