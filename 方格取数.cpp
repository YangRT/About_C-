#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
int g[10][10];
int N,a,b,c,num=0,ans=0,sum=0;
int dx[2]={1,0};
int dy[2]={0,1};
void dfs(int x,int y){
	if(x== N && y == N){
		if(num==2){
			ans = max(ans,sum);
		}else{
			dfs(1,1);
		}
		return;
	}
	for(int i = 0;i < 2;i++){
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if(nextX > N) continue;
		if(nextY > N) continue;
		int t = g[nextX][nextY];
		
		sum += t;
		g[nextX][nextY] = 0;
		if(nextX==N&&nextY==N) num++;
		dfs(nextX,nextY);
		if(nextX==N&&nextY==N) num--;
		sum -= t;
		g[nextX][nextY]=t;
	}
}
int main(){
	memset(g,0,sizeof(g));
	cin>>N;
	cin>>a>>b>>c;
	while(a||b||c){
		g[a][b] = c;
		cin>>a>>b>>c;
	}
	sum += g[1][1];
	g[1][1] = 0;
	dfs(1,1);
	cout<<ans<<endl;
} 
