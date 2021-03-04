#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1001
using namespace std;

int follow[MAXN][MAXN]={0};
int n,l;
void BFS(int a[],int b[],int m){
	for(int i=0;i<m;i++){
		queue<int> q;
		bool visit[n]={false};
		for(int c=1;c<=n;c++) visit[c]=false;	//一定要初始化！！！！！
		int target=a[i];
		visit[target]=true;
		for(int k=0;k<l;k++){
			if(q.size()==0&&k==0){	//刚开始还没数据进队时
				for(int j=1;j<=n;j++){
					if(follow[target][j]>0&&!visit[j]){
						q.push(j);
						visit[j]=true;
					}
				}
			}
			else{
				int total=q.size();
				while(total-->0){
					target=q.front();
					q.pop();
					for(int j=1;j<=n;j++)
						if(follow[target][j]>0&&!visit[j]){
							q.push(j);
							visit[j]=true;
						}
				}
			}
			b[i]+=q.size();
		}
	}
}
int main(){
	int tmp,sum;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum);
		for(int j=0;j<sum;j++){
			scanf("%d",&tmp);
			follow[tmp][i]=1;
		}
	}
	scanf("%d",&sum);
	int query[sum]={0},ans[sum]={0};
	for(int i=0;i<sum;i++){
		scanf("%d",&query[i]);
	}
	BFS(query,ans,sum);
	for(int i=0;i<sum;i++) printf("%d\n",ans[i]);
	system("pause");
	return 0;
}