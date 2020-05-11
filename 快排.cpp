#include<iostream>
using namespace std;

void Swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}

int solution(int a[],int b,int e){
	int i = b;
	int j = e + 1;
	int x = a[b];
	while(true){
		while(a[++i] < x && i < e);
		while(a[--j] > x);
		if(i >= j) break;
		Swap(a[i],a[j]);
	}	
	a[b] = a[j];
	a[j] = x;
	return j;
} 

void quickSort(int a[],int p,int r){
	if(p < r){
		int q = solution(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}
int main(){
	int arry[20];
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>arry[i];
	}
	quickSort(arry,0,n-1);
	for(int j = 0;j < n;j++){
		cout<<arry[j]<<endl;
	}
	
}
