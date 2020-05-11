#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;
int mg[1001][1001];
int flag[1001][1001],b[1000001]; 
int n,m,x,y,sum,d=0;
char a;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct location{
	int x,y;
}node,Top;

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>a;
			if(a == '0'){
				mg[i][j] = 0;
			}else{
				mg[i][j] = 1;
			}
		}
	}
	memset(flag,0,sizeof(flag));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(flag[i][j] == 0){
				d++;
				sum = 0;
				queue<location> Q;
				node.x = i;
				node.y = j;
				Q.push(node);
				sum++;
				flag[i][j]=d;
				while(!Q.empty()){
					Top = Q.front();
					Q.pop();
					for(int k = 0;k < 4;k++){			
						int nextX = Top.x + dx[k];
						int nextY = Top.y + dy[k];
						if(nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
						if(flag[nextX][nextY] != 0) continue;
						if(mg[Top.x][Top.y] != mg[nextX][nextY]){
							node.x = nextX;
							node.y = nextY;
							Q.push(node);
							sum++;
							flag[nextX][nextY] = d;
						}				
					}
				}
				b[d] = sum;
			}
		}
	} 
	while(m--){
		cin>>x>>y;
		cout<<b[flag[x][y]]<<endl;
	}
	return 0;
} 
