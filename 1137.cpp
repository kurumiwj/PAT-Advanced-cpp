#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define MAXN 10005
using namespace std;

struct student{
	string name;
	int gradep,grademid,gradefinal,grade;
};
map<string,int> gp,gmid,gfinal,g;
bool cmp(student a,student b){
	if(a.grade!=b.grade) return a.grade>b.grade;
	else return a.name<b.name;
}
int main(){
	int p,m,n,score;
	string id;
	vector<string> stuid;
	vector<student> st;
	scanf("%d%d%d",&p,&m,&n);
	for(int i=0;i<p;i++){
		cin>>id>>score;
		gp[id]=score;
	}
	for(int i=0;i<m;i++){
		cin>>id>>score;
		gmid[id]=score;
	}
	for(int i=0;i<n;i++){
		student tmp;
		cin>>id>>score;
		if(gmid.find(id)==gmid.end()) gmid[id]=-1;
		gfinal[id]=score;
		if(score>=gmid[id]) g[id]=score;
		else g[id]=(int)(gmid[id]*1.0*0.4+gfinal[id]*1.0*0.6+0.5);
		if(gp[id]>=200&&g[id]>=60){
			tmp.name=id;
			tmp.gradep=gp[id];
			tmp.grademid=gmid[id];
			tmp.gradefinal=gfinal[id];
			tmp.grade=g[id];
			st.push_back(tmp);
		}
	}
	sort(st.begin(),st.end(),cmp);
	for(int i=0;i<st.size();i++){
		cout<<st[i].name<<" "<<st[i].gradep<<" "<<st[i].grademid<<" "<<st[i].gradefinal<<" "<<st[i].grade<<endl;
	}
	system("pause");
	return 0;
}
