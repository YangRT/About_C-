#include<iostream>
using namespace std;
int D1,C,D2,N,P;
struct node{
	int d;
	int p;
}a[200];
int main(){
	cin>>D1>>C>>D2>>P>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i].d>>a[i].p;	
	}
	
	return 0;
} 
