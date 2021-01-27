#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int x[100000];
int main(){
	int n,cnt=0,max=0;
	scanf("%d",&n);
	int a[n]={0},b[n]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		if(a[i]==b[i]&&a[i]>max) x[cnt++]=a[i];
		if(a[i]>max) max=a[i];
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		if(i!=0) printf(" ");
		printf("%d",x[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}