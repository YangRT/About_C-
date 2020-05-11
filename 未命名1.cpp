#include<iostream>
#include<algorithm>
#define MAX 199999
using namespace std;
int a[1000];
int j[100];
int n,k;
bool temp(int a,int b){
	return a > b;
}
int findMin(int min){
	for(int i = 0;i < k;i++){
		if(j[i] < j[min]){
			min = i;
		}
	}
	return min;	
}
int findMax(){
	int max = j[0];
	for(int i = 1;i < k;i++){
		if(j[i] > max){
			max = j[i];
		}
	}
	return max;	
}
int main(){
	
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	for(int i = 0;i < k;i++){
		j[i] = 0;
	}
	int min = 0;
	sort(a,a+n,temp);
	for(int i = 0;i < n;i++){
		j[min] += a[i];
		min = findMin(min);
	}
	cout<<findMax()<<endl;
	return 0;
}
