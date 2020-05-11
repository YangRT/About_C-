#include<iostream>
using namespace std;

void solution(int a[],int n,int b[]){
	int l = 1;
	for(int i = 0;i < n;i++){
		b[i] *= l;
		l *= a[i]; 
	}
	int r = 1;
	for(int j = n -1;j >=0;j--){
		b[j] *= r;
		r *= a[j];
	}
}

int main(){
	int a[50];
	int b[50];
	int n;
	cin>>n;
	for(int j = 0;j < n;j++){
		cin>>a[j];
	}
	for(int k = 0;k < n;k++){
		b[k] = 1;
	}
	solution(a,n,b);
	for(int i = 0;i < n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
