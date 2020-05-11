#include<iostream>
using namespace std;
int main(){
	int a[10] = {45,5,67,13,44,7,11,33,42,5};
	for(int i = 1;i < 10;i++){
		for(int j = 0;j < i;j++){
			if(a[i] <= a[j]){
				int t = i;
				int x = a[i];
				while(t>j){
					a[t] = a[t-1];
					t--;
				}
				a[j] = x;
				break;
			}
		}
	}
	for(int i = 0; i < 10;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
