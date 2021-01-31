#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char name[40005][5];
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(){
	int n,k,m,t;
	scanf("%d%d",&n,&k);
	vector<int> course[k+1];
	for(int i=0;i<n;i++){
		scanf("%s %d",name[i],&m);
		for(int j=0;j<m;j++){
			scanf("%d",&t);
			course[t].push_back(i);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<course[i].size();j++) printf("%s\n",name[course[i][j]]);
	}
	system("pause");
	return 0;
}