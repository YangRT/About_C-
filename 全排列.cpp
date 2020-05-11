#include<iostream>
using namespace std;
int a[20];
void solution(int n,int l){
	if(n == l){
		for(int i = 0;i < l;i++){
			cout<<a[i];
		}
		cout<<endl;
		return;
	}
	for(int j = n;j < l;j++){
		swap(a[n],a[j]);
		solution(n+1,l);
		swap(a[n],a[j]);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	solution(0,n);
	return 0;
} 
