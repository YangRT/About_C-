#include<iostream>
using namespace std;

int partition(int a[],int left,int right){
	int p = a[left];
	int num = left;
	int t = a[right];
	a[right] = p;
	a[left] = t;
	for(int i = left;i <right;i++){
		if(a[i] < p){
			int j = a[i];
			a[i] = a[num];
			a[num] = j;
			num++;			
		}
	}
	t = a[num];
	a[num] = a[right];
	a[right] = t;
	return num+1;
}

int find(int a[],int left,int right,int k){
	int n = partition(a,left,right);
	if(n == k){
		return a[n-1];
	}else{
		if(n > k){
			return find(a,left,n-2,k);
		}else{
			return find(a,n,right,k);
		}
	}
}

int main(){
	int arry[1000];
	int n,k;
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>arry[i];
	}
	int q = find(arry,0,n-1,k);
	cout<<q<<endl;
	return 0;
}
