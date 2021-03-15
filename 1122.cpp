#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#define MAXN 205
using namespace std;

int edge[MAXN][MAXN];
int n,m;
set<int> s;
int main(){
	int v1,v2,k,start,num,next,pre;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		edge[v1][v2]=edge[v2][v1]=1;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		bool flag=true;
		scanf("%d%d",&num,&start);
		s.insert(start);
		pre=start;
		for(int j=1;j<num;j++){
			scanf("%d",&next);
			s.insert(next);
			if(edge[pre][next]==0)
				flag=false;
			pre=next;
		}
		if(flag==false||num!=n+1||next!=start||s.size()!=n) printf("NO\n");
		else printf("YES\n");
		s.clear();
	}
	system("pause");
	return 0;
}
