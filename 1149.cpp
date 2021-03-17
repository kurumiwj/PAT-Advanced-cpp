#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n,m;
vector<int> incompatible[MAXN];
bool canBeSame(vector<int> query){
	bool flag;
	for(int i=0;i<query.size()-1;i++){
		int start=query[i];
		flag=true;
		if(incompatible[start].size()!=0){	//只有商品有不兼容的商品时才遍历否则考虑下一个商品
			for(int j=i+1;j<query.size();j++){
				if(find(incompatible[start].begin(),incompatible[start].end(),query[j])!=incompatible[start].end()){	//只要找到一个不兼容的商品即跳出
					flag=false;
					break;
				}
			}
		}
		if(flag==false) break;
	}
	return flag;
}
int main(){
	int goods1,goods2,k,tmpgoods;
	scanf("%d%d",&n,&m);
	vector<int> query;
	for(int i=0;i<n;i++){
		scanf("%d%d",&goods1,&goods2);
		incompatible[goods1].push_back(goods2);
		incompatible[goods2].push_back(goods1);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&tmpgoods);
			query.push_back(tmpgoods);
		}
		if(canBeSame(query)) printf("Yes\n");
		else printf("No\n");
		query.clear();
	}
	system("pause");
	return 0;
}
