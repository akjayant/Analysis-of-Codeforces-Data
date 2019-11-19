#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

int n;

int f(string s){
	int i0=0;
	int b0=1000;
	int b=0;
	for(int i=0; i<n; ++i){
		b+=(s[i]=='('?1:-1);
		if(b<b0){
			b0=b;
			i0=(i+1)%n;
		}
	}
	b=0;
	int res=0;
	for(int i=i0; i<n; ++i){
		b+=(s[i]=='('?1:-1);
		if(b<0)return 0;
		if(b==0)++res;
	}
	for(int i=0; i<i0; ++i){
		b+=(s[i]=='('?1:-1);
		if(b<0)return 0;
		if(b==0)++res;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>n>>s;
	{
	int o=0,c=0;
	for(int i=0; i<n; ++i){
		if(s[i]=='(')++o;
		else ++c;
	}
	if(o!=c){
		cout<<0<<'\n'<<1<<' '<<1<<endl;
		return 0;
	}
	}
	int resi=1,resj=1;
	int res=f(s);
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			swap(s[i],s[j]);
			int t=f(s);
			if(t>res){
				resi=i+1;
				resj=j+1;
				res=t;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<res<<'\n'<<resi<<' '<<resj<<endl;
	return 0;
}
