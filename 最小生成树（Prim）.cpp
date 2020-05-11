#include<iostream>
using namespace std;
#define  MAX 5555
bool t[100];
int lowcost[100];
int closest[100];
int s[100][100];
int main(){
	int N,W;
	cin>>N>>W;
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			s[i][j] = MAX;
		}
	}
	for(int i = 0;i < W;i++){
		int a,b;
		cin>>a>>b;
		cin>>s[a][b];
		s[b][a] = s[a][b];
	}
	
	t[1] = true;
	
	for(int j = 2;j <= N;j++){
		lowcost[j] = s[1][j];
		closest[j] = 1;
		t[j] = false;
	}
	for(int i = 1;i <= N;i++){
		int min = MAX;
		int k = 1;
		for(int j = 2;j <= N;j++){
			if(t[j] == false && lowcost[j] < min){
				min = lowcost[j];
				k = j;
			}
		} 
		t[k] = true;
		cout<<k<<" "<<closest[k]<<endl;
		for(int i = 2;i <= N;i++){
			if(s[k][i] < lowcost[i] && t[i] == false){
				lowcost[i] = s[k][i];
				closest[i] = k;
			}
		}
	}
	return 0;
}
 
