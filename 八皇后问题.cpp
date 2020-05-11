#include<iostream>
using namespace std;
int ans[20],b[20],c[2][28];
int n,sum=0;

void search(int i){
	if(i>n){	
		sum++;
		if(sum>3){
			return;
		}else{
			for(int j=1;j<=n;j++){
				cout<<ans[j]<<" "; 
			}
			cout<<endl;
			return;
		}
	}
	for(int k=1;k<=n;k++){
		if((!b[k])&&(!c[0][i+k])&&(!c[1][i-k+n])){
			ans[i] = k;
			b[k] = 1;
			c[0][i+k] = 1;
			c[1][i-k+n] = 1;
			search(i+1);
			b[k] = 0;
			c[0][i+k] = 0;
			c[1][i-k+n] = 0;
		}
	}
}

int main(){
	cin>>n;
	search(1);
	cout<<sum<<endl;
	return 0;
} 
