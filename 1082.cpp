#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s1[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string s2[5]={"Yi","Wan","Qian","Bai","Shi"};

void print(int n){
	int a,b,c,d;	//分别代表千百十个位
	if(n<10) cout<<s1[n];
	else if(n>=10&&n<100){
		c=n/10,d=n%10;
		cout<<s1[c]<<" "<<s2[4];
		if(d!=0) cout<<" "<<s1[d];
	}
	else if(n>=100&&n<1000){
		b=n/100,c=n%100/10,d=n%100%10;
		cout<<s1[b]<<" "<<s2[3];
		if(c==0&&d!=0) cout<<" "<<s1[c]<<" "<<s1[d];
		else if(c!=0&&d==0) cout<<" "<<s1[c]<<" "<<s2[4];
		else if(c!=0&&d!=0) cout<<" "<<s1[c]<<" "<<s2[4]<<" "<<s1[d];
	}
	else if(n>=1000&&n<10000){
		a=n/1000,b=n%1000/100,c=n%100/10,d=n%100%10;
		cout<<s1[a]<<" "<<s2[2];
		if(b!=0){
			cout<<" "<<s1[b]<<" "<<s2[3];
			if(c==0&&d!=0) cout<<" "<<s1[c]<<" "<<s1[d];
			else if(c!=0&&d==0) cout<<" "<<s1[c]<<" "<<s2[4];
			else if(c!=0&&d!=0) cout<<" "<<s1[c]<<" "<<s2[4]<<" "<<s1[d];
		}else{
			cout<<" "<<s1[0];
			if(c==0&&d!=0) cout<<" "<<s1[d];
			else if(c!=0&&d==0) cout<<" "<<s1[c]<<" "<<s2[4];
			else if(c!=0&&d!=0) cout<<" "<<s1[c]<<" "<<s2[4]<<" "<<s1[d];
		}
	}
}
int main(){
	int n,n1,n2;
	scanf("%d",&n);
	if(n<0) printf("Fu ");
	if(abs(n)<10000) print(abs(n));
	else if(abs(n)>=10000&&abs(n)<100000000){
		n1=abs(n)/10000,n2=abs(n)%10000;
		print(n1);
		printf(" Wan");
		if(n2<1000&&n2!=0) printf(" ling "),print(n2);
		else if(n2>=1000) printf(" "),print(n2);
	}else if(abs(n)>=100000000){
		int m=abs(n)/100000000;
		print(m);
		printf(" Yi");
		n1=abs(n)%100000000/10000;
		n2=abs(n)%100000000%10000;
		if(n1!=0){
			if(n1<1000) printf(" ling "),print(n1);
			else printf(" "),print(n1);
			printf(" Wan");
			if(n2<1000&&n2!=0) printf(" ling "),print(n2);
			else if(n2>=1000) printf(" "),print(n2);
		}else{
			if(n2!=0) printf(" ling "),print(n2);
		}
	}
	system("pause");
	return 0;
}