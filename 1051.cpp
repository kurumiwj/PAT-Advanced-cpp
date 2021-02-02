#include <iostream>
#include <stack>
using namespace std;

int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	stack<int> s;
	for(int j=0;j<k;j++){
		int min=1;	//min记录下次进栈开始的数
		bool flag=true;	//记录是否是一个合法的出栈序列
		for(int i=0;i<n;i++){
			int t;
			scanf("%d",&t);
			if(flag){
				if(s.empty()||t>s.top()){	//若栈为空或者数字比栈顶元素大则进栈
					for(int l=min;l<=t;l++) s.push(l);
					min=t+1;	//下次进栈从t+1开始
					if(s.size()>m){	//若进栈的数量大于栈容量
						flag=false;
					}
				}
				if(t==s.top()) s.pop();
				else if(t<s.top()){	//若出栈的数字不是栈顶则出错
					flag=false;
				}
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
		while(!s.empty()) s.pop();	//清空栈
	}
	system("pause");
	return 0;
}