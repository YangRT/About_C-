#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void solution(vector<string> &a,int n,int r,string &temp,int l){
	int t = temp.length();
	if(t == r){
		cout<<temp<<endl;
	}
	for(int i = l;i >= 0;i--){
		if(temp.find(a[i]) == string::npos){
			temp += a[i];
			solution(a,n,r,temp,i-1);
			temp.erase(temp.length()-1);
		}
	}
}

int main(){
	vector<string> arry(9);
	arry[0] = "1";
	arry[1] = "2";
	arry[2] = "3";
	arry[3] = "4";
	arry[4] = "5";
	arry[5] = "6";
	arry[6] = "7";
	arry[7] = "8";
	arry[8] = "9";
	int n,r;
	cin>>n>>r;
	string temp;
	solution(arry,n,r,temp,n-1);
}
