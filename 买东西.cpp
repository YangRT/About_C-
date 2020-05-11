#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int v;
	int p;
}a[25];
int x[25];
int b[25][100000];

int min(int a,int b){
	return a>b?b:a;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int N,n,m,t;
	scanf("%d",&N);
	while(N--){
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= m;i++){
			scanf("%d%d",&a[i].v,&a[i].p);
		}
		t = min(a[m].v-1,n);
		for(int j = 0;j <= t;j++) b[m][j] = 0;
		for(int j = a[m].v;j <= n;j++) b[m][j] = a[m].v*a[m].p;
		for(int i = m-1;i > 1;i--){
			t = min(a[i].v-1,n);
			for(int j = 0;j <= t;j++) b[i][j] = b[i+1][j];
			for(int j = a[i].v;j <= n;j++) b[i][j] = max(b[i+1][j],b[i+1][j-a[i].v]+a[i].v*a[i].p);
		}
		b[1][n] = b[2][n];
		if(n >= a[1].v) b[1][n] = max(b[1][n],b[2][n-a[1].v]+a[1].p*a[1].v);
		cout<<b[1][n]<<endl;
		//×îÓÅ½â 
		for(int j = 1;j < m;j++){
			if(b[j][n] == b[j+1][n]) x[j] = 0;
			else{
				x[j] = 1;
				n -= a[j].v;
			}	
		}
		x[m] = (b[m][n])?1:0;
		for(int j = 0;j < m;j++){
			if(x[j] == 1){
				cout<<a[j].v<<" "<<a[j].p<<endl;
			}
		} 
	} 
	return 0;
} 
