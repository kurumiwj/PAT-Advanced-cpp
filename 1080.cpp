#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct student{
	int id,ge,gi,final,rank;	//考生号(从0开始)，笔试成绩，面试成绩，最终成绩，排名
	vector<int> choice;	//每个学生的志愿
	bool admission=false;	//记录每个学生是否已经被录取
};
bool cmp(student a,student b){
	if(a.final!=b.final) return a.final>b.final;
	else if(a.ge!=b.ge) return a.ge>b.ge;
	else return a.id<b.id;
}
bool cmp1(int a,int b){
	return a<b;
}
int main(){
	int n,m,k;	//总报考人数，总学校数，每个学生可以选择的志愿
	scanf("%d%d%d",&n,&m,&k);
	vector<int> school[2];	//第一行每个学校拟录取的人数，第二行上个录取学生的排名
	for(int i=0;i<2;i++) school[i].resize(m);
	for(int i=0;i<m;i++) scanf("%d",&school[0][i]);
	student stu[n];
	for(int i=0;i<n;i++){
		stu[i].id=i;
		stu[i].choice.resize(k);
		scanf("%d%d",&stu[i].ge,&stu[i].gi);
		stu[i].final=(stu[i].ge+stu[i].gi);
		for(int j=0;j<k;j++) scanf("%d",&stu[i].choice[j]);
	}
	sort(stu,stu+n,cmp);
	vector<int> v[m];	//保存每个学校收的人
	for(int i=0;i<n;i++){
		stu[i].rank=i;
		if(i!=0&&stu[i].final==stu[i-1].final&&stu[i].ge==stu[i-1].ge) stu[i].rank=stu[i-1].rank;
	}
	v[stu[0].choice[0]].push_back(stu[0].id);	//第一名的考生必定可以录取
	school[0][stu[0].choice[0]]--,school[1][stu[0].choice[0]]=stu[0].rank;	//录取人数减1
	stu[0].admission=true;
	for(int i=1;i<n;i++)
		for(int j=0;j<k;j++)
			if(stu[i].rank==school[1][stu[i].choice[j]]||school[0][stu[i].choice[j]]>0){	//若报考学校还有名额或该生与志愿学校上一个录取的考生排名相同则一并录取
				stu[i].admission=true;
				v[stu[i].choice[j]].push_back(stu[i].id);
				school[0][stu[i].choice[j]]--;
				school[1][stu[i].choice[j]]=stu[i].rank;
				break;
			}
	for(int i=0;i<m;i++){
		sort(v[i].begin(),v[i].end(),cmp1);
		if(v[i].size()==0) printf("\n");
		else{
			for(int j=0;j<v[i].size();j++){
				printf("%d",v[i][j]);
				if(j!=v[i].size()-1) printf(" ");
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}