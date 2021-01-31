#include <iostream>
#include <string>
using namespace std;

int dotLoc(string a){	//查找小数点的位置
	for(int i=0;i<a.length();i++) if(a[i]=='.') return i;
	return a.length();
}
string scienceForm(string a,int n){
	int i=0,m=-1,k=dotLoc(a);	//m记录第一个不为0的数，k为小数点位置
	for(i=0;i<a.length();i++)
		if(a[i]!='0'&&a[i]!='.'){
			m=i;
			break;
		}
	string s,e;	//s记录有效数位，e记录指数
	s="0.";
	if(m==-1){	//只有0的情况
		for(i=0;i<n;i++) s+='0';
		s+="*10^0";
	}
	else{
		if(m>k){	//若有效部分在小数点后面则指数为负
			int t=m;
			e=m-k-1+'0';
			for(i=0;i<n&&m<a.length();)
				if(a[m]!='.') s+=a[m++],i++;
				else m++;
			if(i!=n)	//字符串位数不够补0
				for(int j=0;j<n-i;j++) s+='0';
			if(t==k+1) s+="*10^"+e;	//若原字符串小数点已经放到正确位置
			else s+="*10^-"+e;
		}else{
			e=k-m+'0';
			for(i=0;i<n&&m<a.length();)
				if(a[m]!='.') s+=a[m++],i++;
				else m++;
			if(i!=n)
				for(int j=0;j<n-i;j++) s+='0';
			s+="*10^"+e;
		}
	}
	return s;
}
int main(){
	int n;
	string a,b;
	scanf("%d",&n);
	cin>>a>>b;
	string sciencea=scienceForm(a,n),scienceb=scienceForm(b,n);
	if(sciencea==scienceb) cout<<"YES "<<sciencea;
	else cout<<"NO "<<sciencea<<" "<<scienceb;
	system("pause");
	return 0;
}