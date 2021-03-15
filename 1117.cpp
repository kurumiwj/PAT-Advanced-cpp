#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){return a>b;}
int main(){
	int n,daydis,e;
	scanf("%d",&n);
	vector<int> dis;
	for(int i=0;i<n;i++){
		scanf("%d",&daydis);
		dis.push_back(daydis);
	}
	sort(dis.begin(),dis.end(),cmp);
	for(e=0;e<dis.size();e++){
		if(dis[e]<=e+1){
			break;
		}
	}
	printf("%d",e);
	system("pause");
	return 0;
}