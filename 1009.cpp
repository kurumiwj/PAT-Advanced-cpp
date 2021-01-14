#include <iostream>
#include <cstdio>
using namespace std;

struct Polynomial{
	int exp;	//指数
	double coe;	//系数
 };
int main(){
	int k,cnt=0;
	double a[2005]={0.0};	//a数组保存计算结果
	Polynomial p[2][10];
	for(int i=0;i<2;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d %lf",&p[i][j].exp,&p[i][j].coe);
			if(i==1)
				for(int t=0;t<10;t++)
					if(p[0][t].coe!=0.0) a[p[0][t].exp+p[1][j].exp]+=(p[0][t].coe*p[1][j].coe);
		}
	}
	for(int i=2000;i>=0;i--) if(a[i]!=0.0) cnt++;
	printf("%d",cnt);
	for(int i=2000;i>=0;i--) if(a[i]!=0.0) printf(" %d %.1f",i,a[i]);
	system("pause");
	return 0;
}