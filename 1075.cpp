#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// struct user{
// 	int id,total=0,perfect=0,rank;
// 	bool flag=false;	//flag用来判断是否提交且通过编译过，防止出现提交通过编译但全部是0分的情况
// 	vector<int> score;
// };
// bool cmp(user a,user b){
// 	if(a.total!=b.total) return a.total>b.total;
// 	else if(a.perfect!=b.perfect) return a.perfect>b.perfect;
// 	else return a.id<b.id;
// }
// int main(){
// 	int n,k,m;	//用户，题目数，记录
// 	scanf("%d%d%d",&n,&k,&m);
// 	vector<user> u(n+1);
// 	for(int i=1;i<=n;i++) u[i].score.resize(k+1,-1);	//初始化为-1方便0的计算
// 	int p[k+1];
// 	for(int i=1;i<=k;i++) scanf("%d",&p[i]);
// 	for(int i=0;i<m;i++){
// 		int id,no,tmp;
// 		scanf("%d%d",&id,&no);
// 		scanf("%d",&tmp);
// 		u[id].id=id;
// 		u[id].score[no]=max(u[id].score[no],tmp);
// 		if(tmp!=-1) u[id].flag=true;
// 		else if(u[id].score[no]==-1) u[id].score[no]=-2;
// 	}
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=k;j++){
// 			if(u[i].score[j]==p[j]) u[i].perfect++;	//统计该题满分的情况
// 			if(u[i].score[j]!=-1&&u[i].score[j]!=-2) u[i].total+=u[i].score[j];
// 		}
// 	}
// 	sort(u.begin()+1,u.end(),cmp);
// 	for(int i = 1; i <= n; i++) {
// 		u[i].rank = i;
// 		if(i != 1 && u[i].total == u[i - 1].total)
// 			u[i].rank = u[i - 1].rank;
// 	}
// 	for(int i = 1; i <= n; i++) {
// 		if(u[i].flag == true) {
// 			printf("%d %05d %d", u[i].rank, u[i].id, u[i].total);
// 			for(int j = 1; j <= k; j++) {
// 				if(u[i].score[j] != -1 && u[i].score[j] != -2)
// 					printf(" %d", u[i].score[j]);
// 				else if(u[i].score[j] == -1)
// 					printf(" -");
// 				else
// 					printf(" 0");
// 			}
// 			printf("\n");
// 		}
// 	}
// 	system("pause");
// 	return 0;
// }
struct user{
	int id,total=0,perfect=0,flag=false,rank;	//flag用来判断是否提交且通过编译过，防止出现提交通过编译但全部是0分的情况
	int score[6]={-1};
};
bool cmp(user a,user b){
	if(a.total!=b.total) return a.total>b.total;
	else if(a.perfect!=b.perfect) return a.perfect>b.perfect;
	else return a.id<b.id;
}
int main(){
	int n,k,m;	//用户，题目数，记录
	scanf("%d%d%d",&n,&k,&m);
	user u[n+1];
	for(int i=1;i<=n;i++) fill(u[i].score,u[i].score+6,-1);	//初始化为-1方便0的计算
	int p[k+1];
	for(int i=1;i<=k;i++) scanf("%d",&p[i]),u[0].total+=p[i]+1;
	for(int i=0;i<m;i++){
		int id,no,tmp;
		scanf("%d%d",&id,&no);
		scanf("%d",&tmp);
		u[id].id=id;
		if(tmp>=u[id].score[no]&&tmp!=-1) u[id].flag=true,u[id].score[no]=tmp;
		else if(tmp==-1&&u[id].score[no]<0) u[id].score[no]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(u[i].score[j]==p[j]) u[i].perfect++;	//统计该题满分的情况
			if(u[i].score[j]==-1);
			else u[i].total+=u[i].score[j];
		}
	}
	sort(u+1,u+n+1,cmp);
	for(int i = 1; i <= n; i++) {
		u[i].rank = i;
		if(i != 1 && u[i].total == u[i - 1].total)
			u[i].rank = u[i - 1].rank;
	}
	for(int i = 1; i <= n; i++) {
		if(u[i].flag == true) {
			printf("%d %05d %d", u[i].rank, u[i].id, u[i].total);
			for(int j = 1; j <= k; j++) {
				if(u[i].score[j] != -1 && u[i].score[j] != -2)
					printf(" %d", u[i].score[j]);
				else if(u[i].score[j] == -1)
					printf(" -");
				else
					printf(" 0");
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}