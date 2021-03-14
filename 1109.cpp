#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAXN 10005
using namespace std;

int n,k;
struct people{
	string name;
	int height;
};
bool cmp(people a,people b){
	if(a.height!=b.height) return a.height>b.height;
	else return a.name<b.name;
}
int index(int x){
	int base=x/2,flag=0;
	if(x%2==0) flag=-1;
	else flag=1;
	return (base+1)*flag;
}
int main(){
	int tmpheight,m,i=0,cnt=0;
	string tmpname;
	scanf("%d%d",&n,&k);
	m=n/k;
	string group[k][MAXN];
	vector<people> p;
	for(int i=0;i<n;i++){
		cin>>tmpname>>tmpheight;
		people tmppeople;
		tmppeople.name = tmpname,tmppeople.height=tmpheight;
		p.push_back(tmppeople);
	}
	sort(p.begin(),p.end(),cmp);
	while(i<k&&i>=0){
		if(i==0){
			int firstRowNum = n-(k-1)*m;
			int tallest_index = firstRowNum/2+1;
			group[i][tallest_index] = p[cnt].name;
			while(cnt<firstRowNum-1){
				int offset = index(cnt);
				cnt++;
				group[i][tallest_index+offset] = p[cnt].name;
			}
			for(int j=1;j<=firstRowNum;j++){
				if(j!=1) printf(" ");
				cout<<group[i][j];
			}
		}else{
			int tallest_index = m/2+1,tmpnum = 0;
			cnt++;
			group[i][tallest_index] = p[cnt].name;
			while(tmpnum<m-1){
				int offset = index(tmpnum);
				cnt++,tmpnum++;
				group[i][tallest_index+offset] = p[cnt].name;
			}
			for(int j=1;j<=m;j++){
				if(j!=1) printf(" ");
				cout<<group[i][j];
			}
		}
		printf("\n");
		i++;
	}
	system("pause");
	return 0;
}