#include<iostream>
#include<cstring>
using namespace std;
//�ַ���Ԥ���� 
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
	int right = 0;  //�ұ߽�λ�� 
	int rightCenter = 0;  //�����ұ߽������ 
	int halfLen[1000] ={0}; //�洢�Ը��ַ�Ϊ���ĵ�����İ뾶 
	int center = 0;  //����İ뾶������ 
	int longestHalf = 0; //����İ뾶 
	for(int i = 1;i < len;i++){
		bool needChange = true;  //�Ƿ���Ҫ�ı䵽���ұ߽������ 
		if(right > i){     //�ڱ߽��� 
			int leftCenter = 2 * rightCenter - i;  // i�������ĵĶԳƵ� 
			halfLen[i] = halfLen[leftCenter];
			if(i + halfLen[i] > right){  //�Ƿ񳬹��ұ߽� 
				halfLen[i] = right - i;
			}
			if(i + halfLen[leftCenter] < right){  //�Ƿ���Ҫ�ı����ģ��ж�i���ϻ��İ뾶�Ƿ񳬹���ǰ�ұ߽磩 
				needChange = false;
			}
		}
		if(needChange){
			while(i-1-halfLen[i] >= 0 && i + 1 + halfLen[i] < len){ //��һ�Ƚ� 
				if(t[i+1+halfLen[i]] == t[i-1-halfLen[i]]){
					halfLen[i]++;
				}else{
					break;
				}
			}
			right = i + halfLen[i];  //�޸��ұ߽� 
			rightCenter = i;  //�޸��ұ߽����� 
			if(halfLen[i] > longestHalf){ //�Ƿ����֮ǰ��뾶 
				center = i;
				longestHalf = halfLen[i];
			}
		}	
	}
	string result;
	for(int i = center - longestHalf + 1;i <= center + longestHalf;i +=2){  //ȥ�� # 
		result += t[i];
	}
	return result; 
}
int main(){
	string test = "cabadabag";
	string result = find(test);
	cout<<"ԭ�ַ���Ϊ"<<test<<endl;
	cout<<"������Ӵ�Ϊ��"<<result<<endl;
	return 0; 
} 
