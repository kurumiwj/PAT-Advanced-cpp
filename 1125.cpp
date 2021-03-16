#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#define MAXN 10005
using namespace std;

int main(){
	int n,length=0,tmp;
	scanf("%d",&n);
	vector<int> rope;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		rope.push_back(tmp);
	}
	sort(rope.begin(),rope.end(),less<int>());
	length=rope[0];
	for(int i=1;i<rope.size();i++){
		length=(length+rope[i])/2;
	}
	printf("%d",length);
	system("pause");
	return 0;
}
