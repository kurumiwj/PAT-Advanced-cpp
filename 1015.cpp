#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long radixChange(int n,int d,int flag){	//若flag为0则将n转换成d进制数，若为1则把d进制下的数n转换成10进制
	long long t=0;
	int exp=0;
	if(flag==0)
		while(n>0){
			t+=(n%d)*pow(10,exp++);
			n/=d;
		}
	else
		while(n>0){
			t+=(n%10)*pow(d,exp++);
			n/=10;
		}
	return t;
}
bool isprime(long long n){
	if(n==1) return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0) return false;
	return true;
}
long long reverse(string n){
	int i=0,j=n.length()-1;
	while(i<j){
		char tmp=n[i];
		n[i]=n[j];
		n[j]=tmp;
		i++,j--;
	}
	return stoll(n);
}
int main(){
	int n=1,d;
	scanf("%d",&n);
	while(n>0){
		scanf("%d",&d);
		long long tmp=radixChange(n,d,0);
		if(isprime(n)&&isprime(radixChange(reverse(to_string(tmp)),d,1))) printf("Yes\n");
		else printf("No\n");
		scanf("%d",&n);
	}
	system("pause");
	return 0;
}