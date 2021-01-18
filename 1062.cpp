#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct student{
	int id;
	int moral_score;	//德分
	int ability_score;	//才分
};

bool cmp(student a,student b){
	if(a.moral_score+a.ability_score!=b.moral_score+b.ability_score)
		return a.moral_score+a.ability_score>b.moral_score+b.ability_score;
	else if(a.moral_score!=b.moral_score) return a.moral_score>b.moral_score;
	else return a.id<b.id;
}
int main(){
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	vector<student> stu[4];	//总共分为4类考生
	int cnt=n;
	for(int i=0;i<n;i++){
		student temp;
		scanf("%d%d%d",&temp.id,&temp.moral_score,&temp.ability_score);
		if(temp.ability_score<l||temp.moral_score<l) cnt--;
		else if(temp.moral_score>=h&&temp.ability_score>=h) stu[0].push_back(temp);
		else if(temp.ability_score>=l&&temp.moral_score>=h) stu[1].push_back(temp);
		else if(temp.moral_score>=temp.ability_score&&temp.ability_score>=l) stu[2].push_back(temp);
		else stu[3].push_back(temp);
	}
	printf("%d\n",cnt);
	for(int i=0;i<4;i++){
		sort(stu[i].begin(),stu[i].end(),cmp);
		for(int j=0;j<stu[i].size();j++) printf("%d %d %d\n",stu[i][j].id,stu[i][j].moral_score,stu[i][j].ability_score);
	}
	system("pause");
	return 0;
}