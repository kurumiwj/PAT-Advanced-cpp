#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

int couple[MAXN];
bool guests[MAXN];
vector<int> single;
int main(){
	int n,id1,id2,m,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&id1,&id2);
		couple[id1]=id2,couple[id2]=id1;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&tmp);
		guests[tmp]=true;
	}
	for(int i=0;i<MAXN;i++){
		if(guests[i]&&guests[couple[i]]) guests[i]=guests[couple[i]]=false;
		else if(guests[i]) single.push_back(i);
	}
	sort(single.begin(),single.end());
	printf("%d\n",single.size());
	for(int i=0;i<single.size();i++){
		if(i!=0) printf(" ");
		printf("%05d",single[i]);
	}
	system("pause");
	return 0;
}