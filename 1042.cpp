#include <iostream>
#include <string>
using namespace std;

char c[6]={"SHCDJ"};
int main(){
	int start[55],end[55],a[55];
	int n;
	scanf("%d",&n);
	for(int i=1;i<55;i++){
		scanf("%d",&a[i]);
		end[i]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<55;j++) start[j]=end[j];
		for(int k=1;k<55;k++) end[a[k]]=start[k];
	}
	for(int i=1;i<55;i++){
		end[i]--;
		printf("%c%d",c[end[i]/13],end[i]%13+1);
		if(i!=54) printf(" ");
	}
	system("pause");
	return 0;
}