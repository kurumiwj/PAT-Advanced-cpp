#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct stu{
	char number[13];
	int score;
	int location;
	int local_rank;
	int final_rank;
};

bool cmp1(stu s1,stu s2){
	return s1.score>s2.score;
}

bool cmp(stu s1,stu s2){
	if(s1.score!=s2.score) return s1.score>s2.score;
	else return strcmp(s1.number,s2.number)<0;
}

int main(){
	int n,m,i,j,k,sum=0,cnt=1;
	scanf("%d",&n);
	stu st[30000];
	for(i=0;i<n;i++){
		scanf("%d",&m);
		for(j=sum;j<sum+m;j++){
			scanf("%s %d",st[j].number,&st[j].score);
			st[j].location=i+1;
		}
		sort(st+sum,st+sum+m,cmp1);	//按照分数从大到小排序
		st[sum].local_rank=1;
		for(j=sum+1;j<sum+m;j++){	//确定各个分组的排名
			while(st[j].score==st[j-1].score){
				st[j].local_rank=st[j-1].local_rank;
				cnt++;	//分数重复的人数
				j++;
			}
			st[j].local_rank=st[j-1].local_rank+cnt;
			cnt=1;
		}
		sum+=m;
	}
	sort(st,st+sum,cmp);
	st[0].final_rank=1;
	for(j=1;j<sum;j++){	//确定全部学生的排名
		while(st[j].score==st[j-1].score){
			st[j].final_rank=st[j-1].final_rank;
			cnt++;	//分数重复的人数
			j++;
		}
		st[j].final_rank=st[j-1].final_rank+cnt;
		cnt=1;
	}
	printf("%d\n",sum);
	for(j=0;j<sum;j++)
		printf("%s %d %d %d\n",st[j].number,st[j].final_rank,st[j].location,st[j].local_rank);
	system("pause");
	return 0;
}