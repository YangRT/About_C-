#include<iostream>
#include<cstdio>
using namespace std;
int arry[1000000];
int w[1000000];
int main(){
	int N;
	cin>>N;
	while(N--){
		int n;
		cin>>n;
		for(int i = 0;i < n;i++){
			scanf("%d",&arry[i]);
		}
		w[0]=arry[0];
		for(int i = 1;i < n;i++){
			if(w[i-1]+arry[i] > arry[i]){
				w[i] = w[i-1]+arry[i];
			}else{
				w[i] = arry[i];
			}
		}
		int max = w[n-1];
		for(int j = n-1;j >= 0;j--){
			if(w[j] > max){
				max = w[j];
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
