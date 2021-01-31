#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int findCommon(set<int> a,set<int> b){
	int common=0;
	for(auto it=b.begin();it!=b.end();it++){
		if(a.find(*it)!=a.end()) common++;
	}
	return common;
}
int main(){
	int n,m,common,total,k;
	scanf("%d",&n);
	vector<set<int>> v(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%d",&tmp);
			v[i].insert(tmp);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int set1,set2;
		scanf("%d%d",&set1,&set2);
		common=findCommon(v[set1],v[set2]);
		total=v[set1].size()+v[set2].size()-common;
		double similarity=common*1.0/total;
		printf("%.1lf%%\n",similarity*100);
	}
	system("pause");
	return 0;
}