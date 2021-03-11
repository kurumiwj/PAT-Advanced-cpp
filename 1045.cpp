#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,l;
int favoriteColor[210];
int stripeColor[10010];
vector<int> a;
int favColor[210];	//记录是否是eva喜欢的颜色并且记录位置
int main(){
	scanf("%d%d",&n,&m);
	int length=0;
	fill(favColor,favColor+210,-1);
	for(int i=0;i<m;i++){
		scanf("%d",&favoriteColor[i]);
		favColor[favoriteColor[i]]=i;
	}
	scanf("%d",&l);
	int dp[l];
	for(int i=0;i<l;i++){
		scanf("%d",&stripeColor[i]);
		if(favColor[stripeColor[i]]!=-1) a.push_back(stripeColor[i]);
	}
	for(int i=0;i<a.size();i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(favColor[a[j]]<=favColor[a[i]]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
		}
		length=max(dp[i],length);
	}
	printf("%d",length);
	system("pause");
	return 0;
}