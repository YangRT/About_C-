#include<iostream>
#include<cstring>
using namespace std;
int n,m[1000001],size,w[1000001],step=0; 
string s;

void init(){
	int l = s.length();
	int num = 0;
	for(int i = l-1;i >= 0;i--){
		if(s[i] >= '0' && s[i] <= '9'){
			m[i] = s[i] - '0';
			num++;
		}else{
		    m[i] = s[i] -'A'+10;
		    num++;
		}
	}
}

void reverse(int t[]){
	int num = size;
	for(int i = 0;i <= size - 1;i++){
		t[i] = m[--num];
	} 
}

void add(){
	int temp,j;
	for(int t = 0;t < size;t++){
		temp += m[t] + w[t];
		j = temp / n;
		m[t] = temp % n;
		temp = j;
	}
	if(temp>0){
		size++;
		m[size-1] = temp;
	}
}

bool isTurn(int a[]){
	int ln = size;
    int i = 0;
    int j = size-1;
    while(ln--)
    {
        if(ln < size/2) 
        {
            break;
        }
        if(a[i] != a[j])
        {
            return false; 
        }
        i++;
        j--;
    }
    return true;
}


int main(){
	cin>>n;
	cin>>s;
    init(); 
    size = s.length();
    while(!isTurn(m)) {
        reverse(w);
        add(); 
        step++;
        if(step > 30) 
        {
            break;
        }
    }
    if(step > 30){
        cout<<"Impossible!"; 
    }
    else{
        cout<<"STEP="<<step<<endl;
    }
    return 0;
	
} 
