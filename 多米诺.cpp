#include<iostream>
#include<cmath>
using namespace std;
int dp[1001][6005];
int x[1001][6005];
int w[1001];
int v[1001];
int n,sum=0,b=0;
int main(){
	cin>>n;
	int t,k;
	for(int i = 1;i <= n;i++){
		cin>>t>>k;
		if(t>k){
			v[i] = 2 * (t - k);
			w[i] = 1;
			sum += t - k;	
		}
		if(k>t){
			v[i] = 2 * (k - t);
			w[i] = -1;
			sum += k - t;
			b++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= sum;j++){
			dp[i][j] = dp[i-1][j];
			x[i][j] = x[i-1][j];
			if(x[i-1][j-v[i]] || j-v[i] == 0){
				if(!x[i][j]){
					dp[i][j] = dp[i-1][j-v[i]] + w[i];
					x[i][j] = 1;
				}else{
					dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
				}
			}
		}
	} 
	int i;
	for(i = sum;i >= 1;i--){
		if(x[n][i]) break;
	} 
	cout<<b+dp[n][i]<<endl;
	return 0;
} 
