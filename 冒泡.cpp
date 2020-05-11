#include<iostream>
using namespace std;
int main(){
	int a[10] = {1,5,12,15,1,44,17,55,33,22};
	for(int i = 9;i > 0;i--){
		for(int j = 0;j < i;j++){
			if(a[j] > a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t; 
			}
		}
	}
	for(int i = 0;i < 10;i++){
		cout<<a[i]<<" "; 
	}
	return 0;
} 
