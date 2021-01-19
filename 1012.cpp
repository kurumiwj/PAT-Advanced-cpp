#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct student{
	int id;
	int score[4];	//平均分，C语言，数学，英语
	int rank[4]={0};	//各科的排名，按优先权即ACME
};
int t;
bool cmp(student a,student b){return a.score[t]>b.score[t];}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	student stu[n];
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3;
	}
	for(t=0;t<4;t++){
		sort(stu,stu+n,cmp);
		stu[0].rank[t]=1;
		int cnt=1,same=1;	//记录排名数和相同分数的人
		for(int j=1;j<n;j++){
			if(stu[j].score[t]<stu[j-1].score[t]){
				cnt=cnt+same;
				stu[j].rank[t]=cnt;
				same=1;
			}
			else stu[j].rank[t]=cnt,same++;
		}
		// for(int i=0;i<n;i++){
		// 	printf("%d %d %d %d %d\n",stu[i].id,stu[i].rank[0],stu[i].rank[1],stu[i].rank[2],stu[i].rank[3]);
		// }
	}
	for(int i=0;i<m;i++){
		int id,j=0;
		scanf("%d",&id);
		for(j=0;j<n;j++)
			if(stu[j].id==id){
				int max=0;	//记录最高排名
				for(int k=0;k<4;k++)
					if(stu[j].rank[k]<stu[j].rank[max]) max=k;
				char C;
				switch(max){
					case 0:C='A';break;
					case 1:C='C';break;
					case 2:C='M';break;
					case 3:C='E';break;
				}
				printf("%d %c\n",stu[j].rank[max],C);
				break;
			}
		if(j==n) printf("N/A\n");
	}
	system("pause");
	return 0;
}