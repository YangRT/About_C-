#include<iostream>
using namespace std;
int main(){
	int n,arry[200][200],b[200],i,j;
	cin>>n;
	for(j = 0;j < n-1;j++){
		for(i = j+1;i < n;i++){
		cin>>arry[j][i];
		}
	}
	for(int k = 0;k < n;k++){
		b[k] = 0;
	}
	for(i = 1;i < n;i++){
		b[i] = b[i-1]+arry[i-1][i];
		for(j = 0;j < i;j++){
			if(arry[j][i]+b[j] <b[i]){
				b[i] = arry[j][i]+b[j];
			}
		}
	}
	cout<<b[n-1]<<endl;
	return 0;
}
