#include<iostream>
using namespace std;
int flag,sum=0;
int s[100], x[100], n,c;
void backtrack(int t)
{
	int i;
	if(sum>c){
		return;
	}
	if(t==n)
	{
		if(sum==c)
		{
			flag=1;
			for(i=0;i<n;i++)
				if(x[i]) cout<<s[i]<<" ";
			return;
		}
	}
	else
	{
		sum+=s[t];
		x[t]=1;
		backtrack(t+1);
		if(flag == 1){
			return;
		}
		x[t]=0;
		sum-=s[t];
		backtrack(t+1);
		if(flag == 1){
			return;
		}
	}
}
int main()
{
	int i;
	cin>>n>>c;
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
		x[i]=0;
	}
	backtrack(0);
	if(flag == 0){
		cout<<"No Solution!"<<endl; 
	}
	return 0;
}
