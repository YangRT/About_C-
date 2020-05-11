#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[100]="ababxbababcadfdsss";
char p[12] = "babcad";
int next[12];

void getNext(){
	int k;
	int m = strlen(p);
	next[0] = 0;
	for(int i = 1,k=0;i < m;i++){
		while(k>0&&p[k]!=p[i]){
			k = next[k-1];
		}
		if(a[k] == a[i]) k++;
		next[i] = k;
	}
}

int kmp(){
	int n,m;
	int q = 0;
	n = strlen(a);
	m = strlen(p);
	getNext();
	for(int i = 0;i < n;i++){
		while(q > 0 && p[q] != a[i])
		          q = next[q-1];
         if (p[q] == a[i]){
             q++;
        }        
		if (q == m){            
			printf("Pattern occurs with shift:%d\n",(i-m+1));
        }
	}
}
int main(){
     printf("%s\n",a);
     printf("%s\n",p);
     kmp();
     return 0;
} 
