#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
bool cmp(int a,int b){return a>b;}
long long sum(int a,int b){
	long long ret=0;
	for(int i=a;i<=b;i++)
		ret+=v[i];
	return ret;
}
int main(){
	int n,tmp;
	long long sum1=0,sum2=0,ans_sum;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),cmp);
	if(n%2==0){
		sum1=sum(0,n/2-1);
		sum2=sum(n/2,n-1);
		ans_sum=sum1-sum2;
		printf("0 %d",sum1-sum2);
	}else{
		sum1=sum(0,n/2);
		sum2=sum(n/2+1,n-1);
		printf("1 %d",sum1-sum2);
	}
	system("pause");
	return 0;
}