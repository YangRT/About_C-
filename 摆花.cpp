#include<iostream>
using namespace std;
int n,m;
int f[101][101];
int a[101];
int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 0;i <= n;i++) f[i][0] = 1;
	for(int j = 1;j <= n;j++){
		for(int i = 1;i <= m;i++){
			for(int k = i;k >= i - a[j];k--){
				if(k>=0){
					f[j][i] += f[j-1][k];
					f[j][i] %= 1000007;
				}else{
					break;
				}
			}
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
} 
