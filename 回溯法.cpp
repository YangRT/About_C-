#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void work(string digits,string &temp,vector<string> &result,vector<string> dict){
	int len = temp.length(),lend = digits.length();
	if(len == lend){
		result.push_back(temp);
		return;
	}
	for(int i = 0;i < dict[digits[len]-'0'].length();i++){
		temp+=dict[digits[len]-'0'][i];
		work(digits,temp,result,dict);
		temp.erase(temp.length()-1);
	}
} 
int main(){
	vector<string> dict(10);
	dict[2]="abc";
	dict[3]="def";
	dict[4]="ghi";
	dict[5]="jkl";
	dict[6]="mno";
	dict[7]="pqrs";
	dict[8]="tuv";
	dict[9]="wxyz";
	string digits;	
	cin>>digits;
	vector<string> result;
	if(digits.length() == 0){
		cout<<endl;
	}else{
		string temp = "";
		work(digits,temp,result,dict);
		for(vector<string>::const_iterator iter=result.begin();iter != result.end();iter++){
			cout<<(*iter)<<endl;
		}
	}
}
