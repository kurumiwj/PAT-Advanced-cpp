#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>
#define MAXN 10010
using namespace std;

struct family{
	int minmember,membernum,totalsets,totalarea;
	double avgsets,avgarea;
};
family fm[MAXN];
bool hashTable[MAXN];
bool visit[MAXN];
int father[MAXN],sets[MAXN],area[MAXN];
vector<int> leader;
int n;
void init(){
	for(int i=0;i<MAXN;i++)
		father[i]=i;
}
int findFather(int x){
	int v=x;
	while(x!=father[x]) x=father[x];
	while(v!=father[v]){
		father[v]=x;
		v=father[v];
	}
	return x;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA<=faB)
		father[faB]=faA;
	else father[faA]=faB;
}
bool cmp(family a,family b){
	if(a.avgarea!=b.avgarea) return a.avgarea>b.avgarea;
	else return a.minmember<b.minmember;
}
int main(){
	int id,fatherid,matherid,childid,childnum,group=0;
	scanf("%d",&n);
	init();
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		hashTable[id]=true;
		scanf("%d%d",&fatherid,&matherid);
		if(fatherid!=-1){
			hashTable[fatherid]=true;
			Union(fatherid,id);
		}
		if(matherid!=-1){
			hashTable[matherid]=true;
			Union(matherid,id);
		}
		scanf("%d",&childnum);
		for(int i=0;i<childnum;i++){
			scanf("%d",&childid);
			hashTable[childid]=true;
			Union(childid,id);
		}
		scanf("%d%d",&sets[id],&area[id]);
	}
	for(int i=0;i<MAXN;i++){
		if(hashTable[i]){
			int root=findFather(i);
			if(!visit[root]){
				fm[root].membernum=1;
				fm[root].minmember=root;
				visit[root]=true;
				group++;
				leader.push_back(root);
			}else{
				fm[root].membernum++;
			}
			fm[root].totalsets+=sets[i];
			fm[root].totalarea+=area[i];
		}
	}
	for(int i=0;i<group;i++){
		fm[leader[i]].avgarea=fm[leader[i]].totalarea*1.0/fm[leader[i]].membernum;
		fm[leader[i]].avgsets=fm[leader[i]].totalsets*1.0/fm[leader[i]].membernum;
	}
	sort(fm,fm+MAXN,cmp);
	printf("%d\n",group);
	for(int i=0;i<group;i++){
		printf("%04d %d %.3f %.3f\n",fm[i].minmember,fm[i].membernum,fm[i].avgsets,fm[i].avgarea);
	}
	system("pause");
	return 0;
}