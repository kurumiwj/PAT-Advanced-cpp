#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct book{	//记录书籍的信息
	vector<string> info;	//0：ID，1：title，2：author，3：keywords，4：publisher，5：publishyear
};
struct query{	//记录查询信息
	int index;	//查询编号
	string content;	//查询内容
};
bool cmp(book a,book b){
	return a.info[0]<b.info[0];
}
int main(){
	int n,m;
	scanf("%d",&n);
	cin.ignore();
	book b[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++){
			string tmp;
			getline(cin,tmp);
			b[i].info.push_back(tmp);
		}
	sort(b,b+n,cmp);
	scanf("%d",&m);
	cin.ignore();
	query q[m];
	for(int i=0;i<m;i++){
		scanf("%d:",&q[i].index);
		cin.ignore();
		getline(cin,q[i].content);
		printf("%d: ",q[i].index);
		cout<<q[i].content<<endl;
		bool flag=false;	//记录是否有找到
		for(int j=0;j<n;j++){
			if(q[i].index!=3){	//若查找的不是关键词
				if(b[j].info[q[i].index]==q[i].content) cout<<b[j].info[0]<<endl,flag=true;
			}
			else{
				if(b[j].info[3].find(q[i].content)!=string::npos) cout<<b[j].info[0]<<endl,flag=true;
			}
		}
		if(flag==false) printf("Not Found\n");
	}
	system("pause");
	return 0;
}