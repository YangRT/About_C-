#include<iostream>
#include<cstring>
using namespace std;
//字符串预处理 
string preHandlerString(string s){
	int len = s.length();
	string t = "#";
	for(int i = 0;i < len;i++){
		t += s[i];
		t += "#"; 
	} 
	cout<<t<<endl;
	return t;
}

string find(string s){
	string t = preHandlerString(s);
	int len = t.length();
	int right = 0;  //右边界位置 
	int rightCenter = 0;  //到达右边界的中心 
	int halfLen[1000] ={0}; //存储以个字符为中心的最长回文半径 
	int center = 0;  //最长回文半径的中心 
	int longestHalf = 0; //最长回文半径 
	for(int i = 1;i < len;i++){
		bool needChange = true;  //是否需要改变到达右边界的中心 
		if(right > i){     //在边界内 
			int leftCenter = 2 * rightCenter - i;  // i关于中心的对称点 
			halfLen[i] = halfLen[leftCenter];
			if(i + halfLen[i] > right){  //是否超过右边界 
				halfLen[i] = right - i;
			}
			if(i + halfLen[leftCenter] < right){  //是否需要改变中心（判断i加上回文半径是否超过当前右边界） 
				needChange = false;
			}
		}
		if(needChange){
			while(i-1-halfLen[i] >= 0 && i + 1 + halfLen[i] < len){ //逐一比较 
				if(t[i+1+halfLen[i]] == t[i-1-halfLen[i]]){
					halfLen[i]++;
				}else{
					break;
				}
			}
			right = i + halfLen[i];  //修改右边界 
			rightCenter = i;  //修改右边界中心 
			if(halfLen[i] > longestHalf){ //是否大于之前最长半径 
				center = i;
				longestHalf = halfLen[i];
			}
		}	
	}
	string result;
	for(int i = center - longestHalf + 1;i <= center + longestHalf;i +=2){  //去除 # 
		result += t[i];
	}
	return result; 
}
int main(){
	string test = "cabadabag";
	string result = find(test);
	cout<<"原字符串为"<<test<<endl;
	cout<<"最长回文子串为："<<result<<endl;
	return 0; 
} 
