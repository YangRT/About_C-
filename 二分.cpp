#include<iostream>
using namespace std;
int main(){
	int a[222],n;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	int x;
	cin>>x;
	int w = 0;
	int h = n-1;
	while(w <= h){
		int p = (w+h)/2;
		if(x == a[p]){
			cout<<p+1<<endl;
			break;
		}
		if(x < a[p]) h = p-1;
		if(x > a[p]) w = p+1;
	}
	return 0;
}
