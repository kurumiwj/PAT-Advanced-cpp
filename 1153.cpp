#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct node{
	string key;
	int value;
};
bool cmp1(node &a,node &b){
	if(a.value!=b.value) return a.value>b.value;
	else return a.key<b.key;
}
bool cmp2(node &a,node &b){
	if(a.value!=b.value) return a.value>b.value;
	else return a.key<b.key;
}
int main(){
	int n,m,score,queryid,totalnum=0,totalscore=0;
	string card,querycontent;
	scanf("%d%d",&n,&m);
	vector<node> t,v;
	unordered_map<string,int> site;
	for(int i=0;i<n;i++){
		cin>>card>>score;
		node tmp;
		tmp.key=card;
		tmp.value=score;
		t.push_back(tmp);
	}
	sort(t.begin(),t.end(),cmp1);
	for(int i=0;i<m;i++){
		cin>>queryid>>querycontent;
		cout<<"Case "<<i+1<<": "<<queryid<<" "<<querycontent<<endl;
		if(queryid==1){
			totalnum=0;
			for(auto it:t)
			if(it.key[0]==querycontent[0]){
					printf("%s %d\n",it.key.c_str(),it.value);
					totalnum++;
				}
			if(totalnum==0) printf("NA\n");
		}else if(queryid==2){
			totalnum=0,totalscore=0;
			for(auto it:t)
			if(it.key.substr(1,3)==querycontent){
					totalnum++;
					totalscore+=it.value;
				}
			if(totalnum==0) printf("NA\n");
			else printf("%d %d\n",totalnum,totalscore);
		}else{
			v.clear();
			site.clear();
			for(auto it:t)
				if(it.key.substr(4,6)==querycontent)
					site[it.key.substr(1,3)]++;
			for(auto it:site){
				node tmp;
				tmp.key=it.first;
				tmp.value=it.second;
				v.push_back(tmp);
			}
			if(v.size()!=0){
				sort(v.begin(),v.end(),cmp2);
				for(auto it:v)
					printf("%s %d\n",it.key.c_str(),it.value);
			}else printf("NA\n");
		}
	}
	system("pause");
	return 0;
}
