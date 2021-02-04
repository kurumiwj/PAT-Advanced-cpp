#include <iostream>
#include <queue>
using namespace std;

const int MAXL=70,MAXM=1300,MAXN=130;
struct Node{
	int x,y,z;	//每个像素点的坐标
	int data;	//每个像素点保存的数据
}Start,End;
int X[6]={1,-1,0,0,0,0},Y[6]={0,0,1,-1,0,0},Z[6]={0,0,0,0,1,-1};	//偏移量
int M,N,L,T,t=0,sum=0;	//每个切片M*N像素矩阵，L切片的数量，T每个核心区至少含有的1数量,sum记录总1数，t记录是否满足核心区的条件数量，total记录访问的总数
bool flag[MAXL][MAXM][MAXN]={false};	//记录每个像素点是否已经访问过，初始全为false
int slice[MAXL][MAXM][MAXN]={0};	//存放每个像素点的数据

bool valid(Node a){	//判断给出的点坐标是否有效
	if(a.x<0||a.x>=L||a.y<0||a.y>=M||a.z<0||a.z>=N||a.data==0||flag[a.x][a.y][a.z]==true) return false;
	return true;
}

int BFS(int x,int y,int z){
	int cnt=0;	//cnt记录每个区块1的个数
	queue<Node> q;
	Node s;
	s.x=x,s.y=y,s.z=z;
	q.push(s);
	flag[s.x][s.y][s.z]=true;
	while(!q.empty()){
		Node a=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<6;i++){
			Node b=a;
			b.x+=X[i],b.y+=Y[i],b.z+=Z[i];
			b.data=slice[b.x][b.y][b.z];
			if(valid(b))	//若b是有效像素点
				q.push(b),flag[b.x][b.y][b.z]=true;	//记录是否访问过
		}
	}
	if(cnt>=T) return cnt;
	else return 0;
}

int main(){
	int cnt=0;	//记录总共的像素点数
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(int i=0;i<L;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++)
				scanf("%d",&slice[i][j][k]);
	Start.x=0,Start.y=0,Start.z=0,Start.data=slice[0][0][0];
	End.x=L-1,End.y=M-1,End.z=N-1,End.data=slice[L-1][M-1][N-1];
	for(int i=0;i<L;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++)
				if(slice[i][j][k]==1&&flag[i][j][k]==false)
					sum+=BFS(i,j,k);
	printf("%d\n",sum);
	system("pause");
	return 0;
}