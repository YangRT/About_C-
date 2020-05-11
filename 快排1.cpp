#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int Partition(int a[],int b,int e){
		int s = b+1;
		int w = e;
		int t = a[b];
		while(true){
			while(a[s] < t&&s < e) s++;
			while(a[w] > t) w--;
			if(s >= w) break;
			int q = a[s];
			a[s] = a[w];
			a[w] = q;
		}
		a[b] = a[w];
		a[w] = t;
		return w;
}

void QuickSort(int a[],int b,int e){
	if(b<e){
		int p = Partition(a,b,e);
		QuickSort(a,b,p-1);
		QuickSort(a,p+1,e);
	}
}
int main(){
	int a[29];
	int n;
	scanf("%d",&n);
	 for(int i = 0;i < n;i++){
	 	scanf("%d",&a[i]);
	 }
	 QuickSort(a,0,n-1);
	 for(int i = 0;i < n;i++){
	 	cout<<a[i]<<" ";
	 }
	 return 0;
} 
