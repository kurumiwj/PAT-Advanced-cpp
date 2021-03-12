#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool cmp(int a,int b){return a>b;}
int findM(int n){
	int end=(int)sqrt(n*1.0),ret=1;
	for(int i=n;i>=end;i--){
		if(n%i==0){
			if(i>=n/i){
				ret=i;
			}
		}
	}
	return ret;
}
int main(){
	int N,tmp;
	scanf("%d",&N);
	vector<int> a;
	for(int i=0;i<N;i++){
		scanf("%d",&tmp);
		a.push_back(tmp);
	}
	sort(a.begin(),a.end(),cmp);
	int m=findM(N),n=N/m,cnt=0,line=1,col=1;
	int ans[m+1][n+1];
	for(int i=0;i<=m;i++) fill(ans[i],ans[i]+n+1,0);
	int left=1,up=1,right=n,down=m;
	if(N==1){
		printf("%d",a[0]);
	}else{
		while(cnt<N){
			while(cnt<N&&col<right){	//向右储存
				ans[line][col++]=a[cnt++];
			}
			while(cnt<N&&line<down)	//向下储存
				ans[line++][col]=a[cnt++];
			while(cnt<N&&col>left)	//向左存储
				ans[line][col--]=a[cnt++];
			while(cnt<N&&line>up)	//向上存储
				ans[line--][col]=a[cnt++];
			left++,right--,up++,down--;
			line++,col++;
			if(cnt==N-1)
				ans[line][col]=a[cnt++];
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(j!=1) printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}