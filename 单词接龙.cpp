#include<iostream>
#include<cstring>
#include<cmath>
using namespace std; 
int n,dic[21][21],s[21],ans;
string w[21];
char t;
void init(string a,string b,int x,int y){
	int A = a.size()-1;
	int B = b.size()-1;
	for(int i=0;i<=B;i++){
		if(a[0] == b[i]){
			int p = 0,sum=0;
			for(int j=i;j<=B;j++){
				if(a[p]==b[j]){
					p++;
					sum++;
					if(j==B&&(sum!=min(A,B)+1)){
						dic[x][y] = sum;
					}
				}else{
					break;
				}
			}
		}
	}
}

void search(int l,int sum){
	ans = max(ans,sum);
	for(int i=1;i<=n;i++){
		if(dic[i][l] && s[i]){
			s[i]--;
			int total = sum+w[i].size()-dic[i][l];
			search(i,total);
			s[i]++;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		s[i]=2;
	}
	cin>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			init(w[i],w[j],i,j);
		}
	}
	for(int i=1;i<=n;i++){
		if(w[i][0] == t){
			s[i]--;
			search(i,w[i].size());
			s[i]++;
		}
	}
	cout<<ans<<endl;
	return 0;
	
}
