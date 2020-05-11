#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x=1215752191;
int a[101];
int b[101][101][11];
int s[101][101][11]; 

int mod(int s)
{
    return ((s%10)+10)%10;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1;i<=2*n;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			b[i][j][1]=s[i][j][1]=mod(a[j]-a[i-1]);
		}
	}
	for(int t=2;t<=m;t++){
		for(int i =1;i<=2*n;i++){
			for(int j=t+i-1;j<=2*n;j++){
				s[i][j][t] = x;
			}
		}
	}
	for (int t=2;t<=m;t++)
      for (int i=1;i<=2*n;i++)
        for (int j=i+t-1;j<=2*n;j++){
            for (int k=i+t-2;k<j;k++){
                s[i][j][t]=min (s[i][j][t],s[i][k][t-1]*mod(a[j]-a[k]));
                b[i][j][t]=max (b[i][j][t],b[i][k][t-1]*mod(a[j]-a[k]));
          }
        }
    int Max=0,Min=x;
	for (int i=1;i<=n;i++)
    {
        Max=max(Max,b[i][i+n-1][m]);
        Min=min(Min,s[i][i+n-1][m]);
    }   
    cout<<Min<<endl;
    cout<<Max<<endl;
    return 0;
}
