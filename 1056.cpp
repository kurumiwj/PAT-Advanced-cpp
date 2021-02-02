#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int np,ng;	//np总人数，ng每组最大人数
	scanf("%d%d",&np,&ng);
	vector<int> a(np+1),b(np);	//a每个人的序号，b每个人的排名
	queue<int> q;
	for(int i=0;i<np;i++) scanf("%d",&a[i]);
	a[np]=-1;	//哨兵
	for(int i=0;i<np;i++){	//所有选手按分组序列进队列
		int tmp;
		scanf("%d",&tmp);
		q.push(tmp);
	}
	while(!q.empty()){
		bool flag=false;	//记录每轮结束
		int t=q.back(),l=q.size(),length=ceil(l*1.0/ng);	//length记录分组情况
		for(int i=0;i<length;i++){
			int max=np;	//记录每轮赢家
			for(int j=0;j<ng;j++){
				if(a[q.front()]>a[max]) max=q.front();
				b[q.front()]=length+1;
				if(q.front()==t){
					q.pop();
					flag=true;	//该轮已结束
					break;
				}
				q.pop();
			}
			if(l!=1) q.push(max);	//当队列就剩最后一个时就不用继续处理了
			else b[max]=1;	//将最终排名矫正
			if(flag) break;
		}
	}
	for(int i=0;i<np;i++){
		printf("%d",b[i]);
		if(i!=np-1) printf(" ");
	}
	system("pause");
	return 0;
}