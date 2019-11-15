#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string str;
int n;
vector<int> v;

int main(){
	cin >> str;
	for(char chr:str){
		if(chr=='m' || chr=='w'){
			cout << 0;
			return 0;
		}
	}
	n=str.size();
	v.assign(n+2,1);
	for(int i=2;i<=n;i++){
		if(str[i-1] == str[i-2] && (str[i-1]=='u' || str[i-1]=='n')){
			v[i+1]=v[i]+v[i-1];
		} else {
			v[i+1]=v[i];
		}
		v[i+1]%=MOD;
		//cout << v[i+1] << ' ';
	}
	cout << v[n+1];
return 0;
}