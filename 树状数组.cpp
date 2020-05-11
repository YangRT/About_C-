//Ê÷×´Êý×é 
#include<iostream>
using namespace std;
int c[20];
int a[20];
int n; 
int lowbit(int x){
	return x & (-x);	
}

int getSum(int n)
{
    int sum=0;
    while(n>0)
    {
         sum+=c[n];
         n=n-lowbit(n);
    }    
    return sum;
}

void change(int i,int x)
{
     while(i<=n)
     {
          c[i]=c[i]+x;
          i=i+lowbit(i);
     }
}

int main(){
	
} 
