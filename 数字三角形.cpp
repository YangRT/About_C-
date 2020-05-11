#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[1001][1001];
int dp[1001][1001];

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <=i; j++){
			cin>>a[i][j];
			dp[i][j] = a[i][j];
		}
	}
	for(int i = n-1;i >=1;i--){
		for(int j = 1;j <= i;j++){
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + a[i][j];
		}
	}
	cout<<dp[1][1]<<endl;
	return 0;
} 
