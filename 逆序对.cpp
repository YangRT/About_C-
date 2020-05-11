#include<iostream>
#include<cstdio>
using namespace std;
int arry[500000];
int oder(int a[],int b,int e,int m){
	int r[e - b +1];
	int c = 0;
	int k = 0;
	int i = b;
	int j = m + 1;
	while(i <= m && j <= e){
		if(a[i] <= a[j]){
			r[k++] = a[i++];
		}else{
			c += m - i + 1;
			r[k++] = a[j++];
		}
	}
	while(j <= e){
		r[k++] = a[j++];
	}
	while(i <= m){
		r[k++] = a[i++];
	}
	for(k = 0;k < e - b + 1;k++){
		a[b + k] = r[k]; 
	}
	return c;
}
int diver(int a[],int b,int e){
	int t = 0;
	if(b < e){
		int m = (b + e) / 2;
		diver(a,b,m);
		diver(a,m+1,e);
		t = oder(a,b,e,m); 
	}
	return t;
}

int main(){
	int N;
	cin>>N;
	for(int i = 0;i < N;i++){
		scanf("%d",&arry[i]);
	}
	int n = diver(arry,0,N - 1);
	cout<<n<<endl;
	return 0;
} 
