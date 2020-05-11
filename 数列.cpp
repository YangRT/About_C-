#include<iostream>
using namespace std;
long long ans[1001];
int k,n;

void create(int l,int x){
	if(l >= n){
		return;
	}
	int r = l;
	ans[++l] = 1;
	for(int i = 1;i <= x+1;i++){
		ans[l] *= k;
	}
	for(int i = 1;i <= r;i++){
		ans[++l] = ans[i] + ans[r+1];
		if(l>=n){
			return;
		}
	}
	create(l,x+1);
}

int main(){
	cin>>k>>n;
	ans[1] = 1;
	ans[2] = k;
	ans[3] = 1+k;
	create(3,1);
	cout<<ans[n]<<endl;
	return 0;
} 
