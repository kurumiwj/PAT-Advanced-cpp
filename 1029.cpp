#include <iostream>
using namespace std;

int main(){
	int n1,n2,cnt=0,i,j;
	scanf("%d",&n1);
	long long s1[n1];
	for(i=0;i<n1;i++) scanf("%ld",&s1[i]);
	scanf("%d",&n2);
	long long s2[n2];
	for(i=0;i<n2;i++) scanf("%ld",&s2[i]);
	long long s3[n1+n2];
	for(i=0,j=0;i<n1&&j<n2;){	//for循环中间判断条件一定要用&&，不能用逗号！！！
		if(s1[i]<=s2[j]) s3[cnt++]=s1[i++];
		else s3[cnt++]=s2[j++];
	}
	while(j<n2) s3[cnt++]=s2[j++];
	while(i<n1) s3[cnt++]=s1[i++];
	printf("%ld",s3[(n1+n2-1)/2]);
	system("pause");
	return 0;
}