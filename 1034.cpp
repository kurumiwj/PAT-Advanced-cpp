#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define MAXN 30000
using namespace std;

struct gang{
	string head;
	int number=0;
}g[340];
bool cmp(gang a,gang b){
	return a.head<b.head;
}
struct node{
	int next;
	int length;
	node(int _next,int _length){
		next=_next,length=_length;
	}
};
vector<node> adjv[MAXN];
int length[MAXN];
bool visit[MAXN]={false};
map<string,int> stringtoint;
map<int,string> inttostring;
int totalmember,totaltime,maxtime;
string head;
void DFS(int k){
	visit[k]=true;	//无论有没有访问过都要设为true
	if(0==adjv[k].size()) return ;	//若k节点没有边了则返回
	for(int i=0;i<adjv[k].size();i++){
		if(!visit[adjv[k][i].next]){	//k的第i条边未访问
			visit[adjv[k][i].next]=true;
			totalmember++;	//第一次碰到总人数加1
			if(length[adjv[k][i].next]>maxtime){	//确定是否是头目
				maxtime=length[adjv[k][i].next];
				head=inttostring[adjv[k][i].next];
			}
			DFS(adjv[k][i].next);	//继续往下查找
		}
		totaltime+=adjv[k][i].length;	//这里总时间打电话和接电话都要算
	}
	return ;
}
int main(){
	int n,k,tmp,cnt=0,total=1;
	string name1,name2;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>name1>>name2;
		scanf("%d",&tmp);
		if(stringtoint[name1]==0){
			stringtoint[name1]=total;
			inttostring[total]=name1;
			total++;
		}
		if(stringtoint[name2]==0){
			stringtoint[name2]=total;
			inttostring[total]=name2;
			total++;
		}
		adjv[stringtoint[name1]].push_back(node(stringtoint[name2],tmp));
		length[stringtoint[name1]]+=tmp;
		length[stringtoint[name2]]+=tmp;
	}
	for(int i=0;i<MAXN;i++){
		if(adjv[i].size()!=0){
			if(!visit[i]){
				totalmember=1,totaltime=0;
				maxtime=length[i],head=inttostring[i];
				DFS(i);
				if(totalmember>2&&totaltime>k){
					g[cnt].head=head;
					g[cnt].number=totalmember;
					cnt++;
				}
			}
		}
	}
	sort(g,g+cnt,cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		cout<<g[i].head<<" "<<g[i].number<<endl;
	}
	system("pause");
	return 0;
}