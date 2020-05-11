#include<iostream>
using namespace std;
int arry[100][100];
int m,n;
void DFS(int x,int y)
{
if(x<0||x>=m||y<0||y>=n||arry[x][y]!=1)
	return;
	arry[x][y]=0;
	DFS(x-1,y);
	DFS(x,y+1);
	DFS(x,y-1);
	DFS(x+1,y);
}
int main(){
	int N,i,j;
	cin>>N;
	while(N--){
		int sum=0;
		cin>>m>>n;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				cin>>arry[i][j];
			}
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(arry[i][j]==1){
					DFS(i,j);
					sum++;
				}
			}
		}
		cout<<sum<<endl;		
	}
	return 0;
} 
