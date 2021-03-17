#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 10005
using namespace std;

struct edge{
	int v1,v2;
};
int n,m;
vector<edge> e;
bool isColoring(vector<int> q){
	for(int i=0;i<e.size();i++){
		if(q[e[i].v1]==q[e[i].v2]) return false;
	}
	return true;
}
int main(){
	int vertex1,vertex2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&vertex1,&vertex2);
		edge tmpedge;
		tmpedge.v1=vertex1,tmpedge.v2=vertex2;
		e.push_back(tmpedge);
	}
	int k,tmpv;
	scanf("%d",&k);
	vector<int> query;
	set<int> color;
	for(int i=0;i<k;i++){
		color.clear();
		query.clear();
		for(int j=0;j<n;j++){
			scanf("%d",&tmpv);
			color.insert(tmpv);
			query.push_back(tmpv);
		}
		if(isColoring(query)) printf("%d-coloring\n",color.size());
		else printf("No\n");
	}
	system("pause");
	return 0;
}
