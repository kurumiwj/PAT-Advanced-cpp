#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,cnt=0,t,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[t]=i;
	}
	for(i=1;i<n;i++){
		if(i!=a[i]){
			while(a[0]!=0){
				swap(a[0],a[a[0]]);
				cnt++;
			}
			if(i!=a[i]){
				swap(a[0],a[i]);
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	system("pause");
	return 0;
}