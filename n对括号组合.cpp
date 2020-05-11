#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void work(int &left,int &right,string &temp,vector<string> &result,int n){
	if(left == n&&right == n){
		result.push_back(temp);
		return;
	}
	if(left < n){
		temp += "(";
		left += 1;
		work(left,right,temp,result,n);
		temp.erase(temp.length() - 1);
		left -= 1;
	}
	if(left > right){
		temp +=")";
		right += 1;
		work(left,right,temp,result,n);
		temp.erase(temp.length()-1);
		right -= 1;
	}
}

vector<string> solution(int n){
	int left = 0,right = 0;
	vector<string> result;
	if(n == 0){
		return result;
	}
	string temp = "(";
	left = 1;
	work(left,right,temp,result,n);
	return result;
}

int main(){
	int n;
	cin>>n;
	vector<string> result = solution(n);
	for(vector<string>::const_iterator iter=result.begin();iter != result.end();iter++){
		cout<<(*iter)<<endl;
	}
	return 0;
}


 
