#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	int l;
	int w;
}arry[1000];
int t[1000];
bool temp(node a,node b){
	return a.l < b.l; 
} 
int main(){
	int n;
	cin>>n;
	while(n--){
		int N,a,b;
		cin>>N;
		for(int i = 0;i < N;i++){
			scanf("%d",&a);
			scanf("%d",&b);
			if(a>b){
				arry[i].l = a;
				arry[i].w = b;
			}else{
				arry[i].l = b;
				arry[i].w = a;
			}
		}
		sort(arry,arry+N,temp);	
		for(int i = 0;i < N;i++){
			t[i] = 0;
		}
		for(int i = 1;i < N;i++){
			for(int j = 0;j < i;j++){
				if(arry[i].l > arry[j].l && arry[i].w > arry[j].w && t[j]+1 > t[i]){
					t[i] = t[j] + 1;
				}
			}
		}
		int max = 0;
		for(int i = N-1;i >= 0;i--){
			if(t[i] > max){
				max = t[i];
			}
		}
		if(max>0){
			cout<<max+1<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
} 
