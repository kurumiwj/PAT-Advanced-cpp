#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,m;	//总硬币，需要付的钱
	scanf("%d%d",&n,&m);
	int coins[n];
	for(int i=0;i<n;i++) scanf("%d",&coins[i]);
	sort(coins,coins+n);
	int i,j;
	bool flag=false;
	for(i=0;i<n-1;i++){
		if(i!=0&&coins[i]==coins[i-1]) continue;
		if(coins[i]>m) break;
		for(j=i+1;j<n;j++)
			if(coins[i]+coins[j]==m){
				flag=true;
				break;
			}
		if(flag==true) break;
	}
	if(flag==true) printf("%d %d",coins[i],coins[j]);
	else printf("No Solution");
	system("pause");
	return 0;
}