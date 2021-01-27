#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) scanf("%d",&b[i]);
	for(i=0;i<n-1&&b[i]<=b[i+1];i++);
	for(j=i+1;a[j]==b[j]&&j<n;j++);
	if(j==n){
		printf("Insertion Sort\n");
		sort(a,a+i+2);
	}
	else{
		printf("Merge Sort\n");
		bool flag=true;
		j=1;
		while(flag){
			flag=false;
			for(i=0;i<n;i++)
				if(a[i]!=b[i]) flag=true;
			j*=2;
			for(i=0;i<n/j;i++)
				sort(a+i*j,a+(i+1)*j);
			sort(a+i*j,a+n);
		}
	}
	for(j=0;j<n;j++){
		printf("%d",a[j]);
		if(j!=n-1) printf(" ");
	}
	system("pause");
	return 0;
}