#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0) return false;
	return true;
}
int smallestPrime(int n){
	if(isPrime(n));
	else
		while(!isPrime(n)) n++;
	return n;
}
int main(){
	int m,n,index;	//index记录取余后的下标
	scanf("%d%d",&m,&n);
	m=smallestPrime(m);
	bool a[m]={false};	//false表示未被占据
	fill(a,a+m,false);
	for(int i=0;i<n;i++){
		int tmp,incrument=1,t;
		scanf("%d",&tmp);
		index=tmp%m;
		if(a[index]==false){
			a[index]=true;
			printf("%d",index);
		}
		else{
			while(incrument<m){
				t=tmp+incrument*incrument;
				index=t%m;
				if(a[index]==false){
					a[index]=true;
					printf("%d",index);
					break;
				}
				incrument++;
			}
			if(incrument>=m) printf("-");
		}
		if(i!=n-1) printf(" ");
	}
	system("pause");
	return 0;
}