
#include<iostream>
#include<cstring> 
using namespace std;

//��֪���������򣬺��������� 
void solution(string a,string b){
	if(a.size() > 0){
		char t = b[b.size()-1];
		cout<<t;
		int k = a.find(t);
		solution(a.substr(0,k),b.substr(0,k));
		solution(a.substr(k+1),b.substr(k,a.size()-k-1));
	}
}

//��֪��������������������֪����㣬�ֱ�ݹ����������ɵú���
void solution2(string a,string b){
	if(a.size()>0){
		char t = a[0];
		int k = b.find(t);
		solution2(a.substr(1,k),b.substr(0,k));
		solution2(a.substr(k+1),b.substr(k+1));
		cout<<t;
	}
} 
int main(){
	 string a,b;
	 cin>>a;
	 cin>>b; 
	 solution2(a,b);
	 cout<<endl;
	 return 0;
} 

