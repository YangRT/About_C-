#include<iostream>
#include<cmath>
using namespace std;
int n,m,x=99999999999;
int a[201],sum[201];
int d[201][201];
int f[201][201];

int all(int a,int b){
	return sum[b] - sum[a-1];
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		a[i+n] = a[i];
		sum[i] = sum[i-1]+a[i];
	}
	for(int i = n+1;i <= n + n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	for(int k = 1;k < n;k++){
		for(int i = 1,j = i+k;(i < n + n) && (j < n + n);i++,j = i + k){
			f[i][j] = 9999999999;
			for(int t = i;t < j;t++){
				d[i][j] = max(d[i][j],d[i][t]+d[t+1][j]+all(i,j));
				f[i][j] = min(f[i][j],f[i][t]+f[t+1][j]+all(i,j));			
			}
		} 
	}
	for(int i = 1;i <= n;i++){
		m = max(m,d[i][i+n-1]);
		x = min(x,f[i][i+n-1]);
	}
	cout<<x<<endl;
	cout<<m<<endl;
	return 0;
}
