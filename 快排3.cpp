#include<iostream>
using namespace std;

int div(int a[],int b,int e){
	int z = a[b];
	int x = b;
	b++;
	while(true){
		while(a[b] < z && b < e) b++;
		while(a[e] > z) e--;
		if(b >= e) break;
		int t = a[b];
		a[b] = a[e];
		a[e] = t;
	}
	a[x] = a[e];
	a[e] = z;
	return e;
}

void quickSort(int a[],int b,int e){
	if(b < e){
		int q = div(a,b,e);
		quickSort(a,b,q-1);
		quickSort(a,q+1,e);
	}
}
int main(){
	int a[10] = {55,12,22,56,98,44,45,12,78,32};
	quickSort(a,0,9);
	for(int i = 0;i < 10;i++){
		cout<<a[i]<<" "; 
	}
	return 0;	 
} 
