#include<iostream>
using namespace std;
int n,k;
int ans[201][7];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		ans[i][1]=1;
		ans[i][0]=1;
	}
	for(int i=2;i<=k;i++){
		ans[1][i]=0;
		ans[0][i]=0;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			if(i>j){
				ans[i][j]=ans[i-1][j-1]+ans[i-j][j];
			}else{
				ans[i][j]=ans[i-1][j-1];
			}
		}
	}
	cout<<ans[n][k]<<endl;
	return 0;
} 
