#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b,int c){
	if(a < b){
		if(a < c){
			return a;
		}else{
			return c;
		}
	}else{
		if(b < c){
			return b;
		}else{
			return c;
		}
	}
}
int min(int a,int b){
	if(a < b){
		return a;
	}else{
		return b;
	}
}
int solution(vector< vector<char> > &matrix){
	int rect=0;
	for(int i = 0;i < matrix.size();i++){
		for(int j = 0;j < matrix[0].size();j++){
			if(matrix[i][j] == '0') continue;
			if(i > 0&&j > 0){
				matrix[i][j]= '1' + min(matrix[i-1][j-1]-'0',matrix[i-1][j]-'0',matrix[i][j-1]-'0');
			}
			rect = (rect >= (matrix[i][j]-'0')?rect:(matrix[i][j]-'0'));
		}
	}
	return rect*rect;
}

int main(){
	int n;
	char t;
	cin>>n;
	vector< vector<char> > matrix;
	matrix.resize(n,vector<char>(n));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin>>t;
			matrix[i][j] = t;
		}
	}
	int s = solution(matrix);
	cout<<s<<endl;
} 
