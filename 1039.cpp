#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct student{
	string name;
	int total_course;
	vector<int> course;
};
int main(){
	int n,k,course,num=0;
	scanf("%d%d",&n,&k);
	student stu[n];
	map<string,int> stuTotalcourse;	//记录每个学生总的课程数
	map<string,vector<int>> stuCourse;	//记录每个学生的课程编号
	for(int i=0;i<k;i++){
		scanf("%d%d",&course,&num);
		for(int j=0;j<num;j++){
			string name;
			cin>>name;
			stuTotalcourse[name]++;
			stuCourse[name].push_back(course);
		}
	}
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		cout<<name<<" "<<stuTotalcourse[name];
		sort(stuCourse[name].begin(),stuCourse[name].end());
		for(auto it=stuCourse[name].begin();it!=stuCourse[name].end();it++)
			cout<<" "<<*it;
		printf("\n");
	}
	system("pause");
	return 0;
}