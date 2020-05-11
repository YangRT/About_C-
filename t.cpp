#include<iostream>
using namespace std;
int a,n,m,x,f[101],y;
int main(){
    cin>>a>>n>>m>>x;
    f[1]=1,f[2]=1;
    for(int i=3;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    y=(m-(f[n-3]+1)*a)/(f[n-2]-1);
    cout<<((f[x-2]+1)*a+(f[x-1]-1)*y)<<endl;
    return 0;
}
