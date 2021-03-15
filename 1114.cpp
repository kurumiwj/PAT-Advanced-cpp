#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#define MAXN 10010
using namespace std;

struct family{
	int minmember,membernum;
	double avgsets,avgarea;
};
int sets[MAXN],area[MAXN];
vector<int> child[MAXN],parents[MAXN];
vector<family> fm;
int n;
bool visit[MAXN]={false},hashTable[MAXN];
void insert(vector<int> &a,int x){
	for(int i=0;i<a.size();i++){
		if(a[i]==x) return ;
	}
	a.push_back(x);
}
bool cmp(family a,family b){
	if(a.avgarea!=b.avgarea) return a.avgarea>b.avgarea;
	else return a.minmember<b.minmember;
}
void DFS(int index,int &minnumber,int &totalnum,int &totalsets,int &totalarea){
	visit[index]=true;
	totalarea+=area[index];
	totalsets+=sets[index];
	if(minnumber>index) minnumber=index;
	for(int i=0;i<parents[index].size();i++){
		if(!visit[parents[index][i]]){
			totalnum++;
			DFS(parents[index][i],minnumber,totalnum,totalsets,totalarea);
		}
	}
	for(int i=0;i<child[index].size();i++){
		if(!visit[child[index][i]]){
			totalnum++;
			DFS(child[index][i],minnumber,totalnum,totalsets,totalarea);
		}
	}
}
int main(){
	int id,fatherid,matherid,childid,childnum;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		scanf("%d%d",&fatherid,&matherid);
		hashTable[id]=true;
		if(fatherid!=-1){
			hashTable[fatherid]=true;
			insert(parents[id],fatherid);
			insert(child[fatherid],id);
		}
		if(matherid!=-1){
			hashTable[matherid]=true;
			insert(parents[id],matherid);
			insert(child[matherid],id);
		}
		scanf("%d",&childnum);
		for(int i=0;i<childnum;i++){
			scanf("%d",&childid);
			insert(child[id],childid);
			insert(parents[childid],id);
		}
		scanf("%d%d",&sets[id],&area[id]);
	}
	for(int i=0;i<MAXN;i++){
		if(!visit[i]&&hashTable[i]){
			int totalnum=1,totalarea=0,totalsets=0,minnumber=MAXN;
			DFS(i,minnumber,totalnum,totalsets,totalarea);
			family tmp;
			tmp.minmember=minnumber,tmp.membernum=totalnum,tmp.avgsets=totalsets*1.0/totalnum,tmp.avgarea=totalarea*1.0/totalnum;
			fm.push_back(tmp);
		}
	}
	sort(fm.begin(),fm.end(),cmp);
	printf("%d\n",fm.size());
	for(int i=0;i<fm.size();i++){
		printf("%04d %d %.3f %.3f\n",fm[i].minmember,fm[i].membernum,fm[i].avgsets,fm[i].avgarea);
	}
	system("pause");
	return 0;
}