#include <iostream>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	long double sum=0.0,t;
	for(int i=0;i<n;i++){
		scanf("%llf",&t);
		sum+=t*(i+1)*(n-i);
	}
	printf("%.2Lf",sum);	//必须用Lf输出
	system("pause");
	return 0;
}