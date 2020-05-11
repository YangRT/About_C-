#include<iostream>
using namespace std;
int a[20],b[20];

void Copy(int l,int r){
	for(int i = l;i <= r;i++){
		a[i] = b[i];
	}
}

void Mergre(int l,int i,int r){
	int k = l;
	int w = i+1;
	while(l <= i && w <= r){
		if(a[l] <= a[w]){
			b[k++] = a[l];
			l++;
		}else{
			b[k++] = a[w];
			w++;
		}
	}
	while(l <= i) b[k++] = a[l++];
	while(w <= r) b[k++] = a[w++];
}
void MergeSort(int left,int right){
	if(left < right){
		int i = (left+right)/2;
		MergeSort(left,i);
		MergeSort(i+1,right);
		Mergre(left,i,right);
		Copy(left,right);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	MergeSort(0,n-1);
	for(int i = 0;i < n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
