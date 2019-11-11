#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

const int MN = 100005;
const ll mod = 1000000007;

ll fib[MN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fib[0]=fib[1]=1;
	for(int i=2; i<MN; ++i)fib[i]=(fib[i-1]+fib[i-2])%mod;
	string s;
	cin>>s;
	s.push_back('o');
	bool imp = (s[0]=='w'||s[0]=='m');
	ll res=1;
	ll hm=1;
	for(int i=1; i<s.size(); ++i){
		imp|=(s[i]=='w'||s[i]=='m');
		if(s[i]==s[i-1])hm++;
		else {
			if(s[i-1]=='u'||s[i-1]=='n'){
				res=(res*fib[hm])%mod;
			}
			hm=1;
		}
	}
	if(imp)res=0;
	cout<<res<<endl;
	return 0;
}