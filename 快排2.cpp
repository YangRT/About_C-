#include<iostream>
#include<cstdio>
using namespace std;
int a[100000];

int partition(int b,int e){
	int x = a[b];
	int l = b+1;
	int r = e;
	while(true){
		while(a[l] <= x && l<e) l++;
		while(a[r] > x) r--;
		if(l>=r) break;
		int t = a[l];
		a[l] = a[r];
		a[r] = t;
	} 
	a[b] = a[r];
	a[r] = x;
	return r;
}

void quickSort(int b,int e){
	if(b<e){
		int p = partition(b,e);
		quickSort(b,p-1);
		quickSort(p+1,e);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	quickSort(0,n-1);
	for(int i = 0;i < n;i++){
		cout<<a[i]<<" ";
	}
} 
