#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct student{
	string name;
	char gender;
	string id;
	int grade;
};
bool cmp_f(student a,student b){
	return a.grade>b.grade;
}
bool cmp_m(student a,student b){
	return a.grade<b.grade;
}
int main(){
	int n,numf=0,numm=0;	//统计男女各多少人
	scanf("%d",&n);
	student stu[n],stu_f[n],stu_m[n];	//男女分别用数组保存
	for(int i=0;i<n;i++){
		string name;
		char gender;
		string id;
		int grade;
		cin>>name>>gender>>id>>grade;
		if(gender=='M'){
			stu_m[numm].name=name,stu_m[numm].gender=gender,stu_m[numm].id=id,stu_m[numm].grade=grade;
			numm++;
		}
		else{
			stu_f[numf].name=name,stu_f[numf].gender=gender,stu_f[numf].id=id,stu_f[numf].grade=grade;
			numf++;
		}
	}
	if(numf!=0){
		sort(stu_f,stu_f+numf,cmp_f);
		cout<<stu_f[0].name<<" "<<stu_f[0].id<<endl;
	}else printf("Absent\n");
	if(numm!=0){
		sort(stu_m,stu_m+numm,cmp_m);
		cout<<stu_m[0].name<<" "<<stu_m[0].id<<endl;
	}else printf("Absent\n");
	if(numm==0||numf==0) printf("NA\n");
	else printf("%d\n",stu_f[0].grade-stu_m[0].grade);
	system("pause");
	return 0;
}