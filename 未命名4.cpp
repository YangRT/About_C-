#include<iostream>
#include<cstdio>
using namespace std;
int n,k,t[20];
int fast=66666;
int len[20];

int comp(){
	int tmp=0;
	for(int i=0; i<k; i++)
		if(len[i]>tmp)
			tmp=len[i];
	return tmp;
}
void search(int dep,int *len,int *t){
	if(dep==n) {
		int tmp=comp();
		if(tmp<fast)
			fast=tmp;
		return;
	}
	for(int i=0; i<k; i++) {
		len[i]+=t[dep];
		if(len[i]<fast)
			search(dep+1,len,t);
		len[i]-=t[dep];
	}
}
int main(){
	int i;
	scanf("%d%d",&n,&k);
	for(i=0; i<k; i++)
		len[i]=0;
	for(int j = 0;j < n;j++){
		scanf("%d",&t[j]);
	}
	search(0,len,t);
	printf("%d\n",fast);
	return 0;
}

