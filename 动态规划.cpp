//最少完全平方数，12=4+4+4,15=9+4+1+1 
#include<iostream>
using namespace std;
int main(){
	int arry[200];
	int n;
	cin>>n;
	for(int j = 0;j < n;j++){
		arry[j] = 0;
	}
	
	for(int i= 1;i <=n;i++){
		int min = 888888;
		for(int j = 1;j*j<=i;j++){
			if(arry[i-j*j]+1<=min){
				min = arry[i-j*j]+1;
			}
		}
		arry[i] = min;
	}
	cout<<arry[n]<<endl;
	return 0;
} 
