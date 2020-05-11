#include<iostream>
using namespace std;
int n,A[100005],B[100005];
int getMiddle()
{
    int AStart=0,AEnd=n-1,BStart=0,BEnd=n-1;
    int a=A[(n-1)/2];
    int b=B[(n-1)/2];
    while(AEnd!=AStart)
    {
        if(a==b)
        {
            return a;
        }
        else if(a<b)
        {
            if(n%2==1)
            {
                AStart=(AStart+AEnd)/2;
                a=A[(AEnd+AStart)/2];
                BEnd=(BStart+BEnd)/2;
                b=B[(BEnd+BStart)/2];
                n=n/2+1;
            }
            else
            {
                AStart=(AStart+AEnd)/2+1;
                a=A[(AEnd+AStart)/2];
                BEnd=(BStart+BEnd)/2;
                b=B[(BEnd+BStart)/2];
                n=n/2;
            }
        }
        else//a>b
        {
            if(n%2==1)
            {
                AEnd=(AStart+AEnd)/2;
                a=A[(AEnd+AStart)/2];
                BStart=(BStart+BEnd)/2;
                b=B[(BEnd+BStart)/2];
                n=n/2+1;
            }
            else
            {
                AEnd=(AStart+AEnd)/2;
                a=A[(AEnd+AStart)/2];
                BStart=(BStart+BEnd)/2+1;
                b=B[(BEnd+BStart)/2];
                n=n/2;
            }
        }
    }
    return a<b?a:b;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    cout<<getMiddle()<<endl;
    
}
