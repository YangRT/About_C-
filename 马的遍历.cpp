#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int p[401][401];
int n,m,fx,fy;
int dx[4]={1,-1,2,-2};
int dy[4]={1,-1,2,-2};
struct location{
	int x;
	int y;
}Top,node;

void bfs(int x,int y,int step){
	p[x][y] = step;
	queue<location> Q;
	node.x = x;
	node.y = y;
	Q.push(node);
	while(!Q.empty()){
		Top = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(abs(dx[i])!=abs(dy[j])){
					int nextX = Top.x + dx[i];
					int nextY = Top.y + dy[j];
					if(nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
					if(p[nextX][nextY] == -1){
						node.x = nextX;
						node.y = nextY;
						Q.push(node);
						p[nextX][nextY] = p[Top.x][Top.y] + 1;
					}
				}	
			}
		}
	}
}
int main(){
	cin>>n>>m>>fx>>fy;	
	memset(p,-1,sizeof(p));
	bfs(fx,fy,0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			printf("%-5d",p[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
