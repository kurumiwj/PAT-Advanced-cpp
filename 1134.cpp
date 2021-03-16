#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAXN 10005
using namespace std;

int n;
int a[MAXN],b[MAXN];
int main(){
	int m,v1,v2,k,num,tmp;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	scanf("%d",&k);
	set<int> query;
	for(int i=0;i<k;i++){
		query.clear();
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&tmp);
			query.insert(tmp);
		}
		int j=0;
		for(j=0;j<m;j++){
			if(query.find(a[j])==query.end()&&query.find(b[j])==query.end()){
				printf("No\n");
				break;
			}
		}
		if(j==m) printf("Yes\n");
	}
	system("pause");
	return 0;
}
