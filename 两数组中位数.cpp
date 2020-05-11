#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a[6] = {34,67,77,87,99,103};
	int b[8] = {12,35,44,57,76,78,85,98};
	int start = 0;
	int end = 6;
	int mid = (6+8+1) / 2;
	while(start <= end){
		int i = (start + end) / 2;
		int j = mid - i;
		if(i < end && b[j-1] > a[i]){
			start = i+1;
		}else if(i > start && a[i-1] > b[j]){
			end = i -1;
		}else{
			int maxLeft;
			if(i == 0){
				maxLeft = b[j-1];
			}else if(j == 0){
				maxLeft = a[i-1];
			}else{
				maxLeft = max(a[i-1],b[j-1]);
			}
			if((8+6) % 2 == 1){
				cout<<maxLeft<<endl;
				break;
			}
			int minRight;
			if(i==6){
				minRight = b[j];
			}else if(j == 8){
				minRight = a[i];
			}else{
				minRight = min(b[j],a[i]);
			}
			cout<<(maxLeft + minRight) / 2.0<<endl;
			break; 
		}
	}
	return 0;
} 
