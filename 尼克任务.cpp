#include<iostream>
#include<algorithm>
using namespace std;
int N,K,P,T;
int dp[10001];

struct node{
	int p;
	int t;
	int j;
}a[10001];
int r[10001];

bool comp(node a,node b){
	return a.p > b.p;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	cin>>N>>K;
	int num = 1;
	for(int i = 1;i <= K;i++){
		cin>>a[i].p>>a[i].t;
		a[i].j = a[i].p+a[i].t-1;
		r[a[i].p]++;
	}
	sort(a+1,a+K+1,comp);
	for(int i = N;i > 0;i--){
		if(r[i] == 0){
			dp[i] = dp[i+1] + 1;
		}else{
			for(int t = 1;t <= r[i];t++){
				dp[i] = max(dp[i],dp[i+a[num].t]);
				num++;
			}
		}
	}
	cout<<dp[1]<<endl;
	
} 
