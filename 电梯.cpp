#include<iostream>
#include<queue>
#include<cstring>
int flag[201];
int k[201];
struct location{
	int l;
	int sum;
}node,top;
int a,b,n,ans;
bool get=false;
using namespace std;
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	if(a == b){
		cout<<0<<endl;
		return 0;
	}
	memset(flag,0,sizeof(flag));
	queue<location> Q;
	node.l = a;
	node.sum = 0; 
	Q.push(node);
	flag[a] = 1;
	while(!Q.empty()&&!get){
		top = Q.front();
		Q.pop();
		if(top.l+k[top.l]<=n&&flag[top.l+k[top.l]]==0){
			flag[top.l+k[top.l]] = 1;
			node.l = top.l+k[top.l];
			node.sum = top.sum + 1;
			Q.push(node);
			if(top.l+k[top.l] == b){
				get = true;
				ans = top.sum + 1;
			}
		}
		if(top.l-k[top.l]>=1&&flag[top.l-k[top.l]]==0){
			flag[top.l-k[top.l]] = 1;
			node.l = top.l-k[top.l];
			node.sum = top.sum + 1;
			Q.push(node);
			if(top.l-k[top.l] == b){
				get = true;
				ans = top.sum + 1;
			}
		}
	} 
	if(get){
		cout<<ans<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
} 
