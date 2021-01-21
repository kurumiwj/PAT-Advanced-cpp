#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct student{
	int id,score;
	string name;
};
bool cmp1(student a,student b){
	return a.id<b.id;
}
bool cmp2(student a,student b){
	if(a.name!=b.name) return a.name<b.name;
	else return a.id<b.id;
}
bool cmp3(student a,student b){
	if(a.score!=b.score) return a.score<b.score;
	else return a.id<b.id;
}
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	student stu[n];
	for(int i=0;i<n;i++){
		scanf("%d",&stu[i].id);
		cin>>stu[i].name;
		scanf("%d",&stu[i].score);
	}
	if(c==1) sort(stu,stu+n,cmp1);
	else if(c==2) sort(stu,stu+n,cmp2);
	else if(c==3) sort(stu,stu+n,cmp3);
	for(int i=0;i<n;i++){
		printf("%06d ",stu[i].id);
		cout<<stu[i].name;
		printf(" %d\n",stu[i].score);
	}
	system("pause");
	return 0;
}