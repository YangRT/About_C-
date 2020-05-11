/*
	区间和，线段树建立，区间更新，查询 
*/
#include<iostream>
using namespace std;
int a[100];
int t[250];
int lazy[250];	//存储下面区间应修改值 

void build(int b,int e,int n){
	if(b == e){
		t[n] = a[b];
		return;
	}else{
		int m = (b+e)/2;
		build(b,m,2*n);
		build(m+1,e,2*n+1);
		t[n] = t[2*n] + t[2*n+1];
	}	
}

void pushdown(int l,int r,int n){
	if(lazy[n]){
		lazy[n*2]  += lazy[n];
		lazy[n*2+1] += lazy[n*2+1];  
		t[n*2] += l*lazy[n];
		t[n*2+1] += r*lazy[n];
		lazy[n] = 0;
	}
}
void update(int L,int R,int C,int b,int e,int n){
	if(L<=b && e<=R){
		t[n] += (e-b+1)*C;
		lazy[n] += C;
		return;
	}
	int m = (b+e)/2;
	pushdown(m-b+1,e-m,n); //先修正值 
	if(L <= m)
		update(L,R,C,b,m,n*2);
	if(R>m)
		update(L,R,C,m+1,e,n*2+1);
	t[n] = t[n*2] + t[n*2+1]; 
}

long long query(int L,int R,int b,int e,int n){
	if(L<=b && e<= R)
		return t[n];
	int m = (b+e)/2;
	pushdown(m-b+1,e-m,n); //先修正值 
	long long ans = 0;
	if(L<=m)	
		ans += query(L,R,b,m,n*2);
	if(R>m)
		ans += query(L,R,m+1,e,n*2+1);
	return ans;		
} 
int main(){
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	build(1,n,1); 
} 
