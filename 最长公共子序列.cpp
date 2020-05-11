#include<iostream>
#include<cstring>
using namespace std;
char a[1001];
char b[1001];
int c[1001][1001];
int main(){
	int N;
	cin>>N;
	while(N--){
		cin>>a>>b;
		int A = strlen(a);
		int B = strlen(b);
		for(int i = 0;i <= A;i++) c[i][0] = 0;
		for(int j = 0;j <= B;j++) c[0][j] = 0;
		for(int i = 1;i <= A;i++){
			for(int j = 1;j <= B;j++){
				if(a[i-1] == b[j-1]){
					c[i][j] = c[i-1][j-1] + 1;
				}else if(c[i-1][j] >= c[i][j-1]){
					c[i][j] = c[i-1][j];
				}else{
					c[i][j] = c[i][j-1];
				}
			}
		}
		cout<<c[A][B]<<endl;
	}
	return 0;
} 

