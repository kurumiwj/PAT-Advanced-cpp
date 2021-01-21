#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct rich{
	string name;
	int age,networth;
};
bool cmp(rich a,rich b){
	if(a.networth!=b.networth) return a.networth>b.networth;
	else if(a.age!=b.age) return a.age<b.age;
	else return a.name<b.name;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rich r[n];
	for(int i=0;i<n;i++){
		cin>>r[i].name;
		scanf("%d%d",&r[i].age,&r[i].networth);
	}
	sort(r,r+n,cmp);
	for(int i=1;i<=k;i++){
		int cnt=0,total,minage,maxage;
		scanf("%d%d%d",&total,&minage,&maxage);
		printf("Case #%d:\n",i);
		for(int j=0;j<n;j++){
			if(r[j].age>=minage&&r[j].age<=maxage){
				cout<<r[j].name;
				printf(" %d %d\n",r[j].age,r[j].networth);
				cnt++;
				if(cnt==total) break;
			}
		}
		if(cnt==0) printf("None\n");
	}
	system("pause");
	return 0;
}