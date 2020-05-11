#include<iostream>
#include<vector>
using namespace std;
vector<int> solution(int a[],int n){
	vector<int> result(0,0);
	int ans_a = a[0];
	int a_num = 1;
	int ans_b = 0;
	int b_num = 0;
	for(int i = 1;i < n;i++){
		if(a[i] == ans_a){
			a_num++;
		}else if(a[i] == ans_b){
			b_num++;
		}else if(a_num == 0){
			ans_a = a[i];
			a_num++;
		}else if(b_num == 0){
			ans_b = a[i];
			b_num++;
		}else{
			a_num--;
			b_num--;
		}
	}
	a_num = 0;
	b_num = 0;
	for(int j = 0;j < n;j++){
		if(a[j] == ans_a) a_num++;
		if(a[j] == ans_b) b_num++; 
	}
	if(a_num > n/3) result.push_back(ans_a);
	if(b_num > n/3) result.push_back(ans_b);
	return result;
} 
int main(){
	int n,arry[50];
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>arry[i];
	}
	vector<int> result = solution(arry,n);
	cout<<result[0]<<endl;
	cout<<result[1]<<endl;
	return 0;
}
