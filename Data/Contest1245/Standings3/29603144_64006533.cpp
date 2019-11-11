#include<bits/stdc++.h>
#define LL long long
#define MAXN 300005
#define INF (1<<25)
#define P int(1e9 + 7)
using namespace std;

int N;
string s;

LL f[MAXN];

int main(){
	
	ios::sync_with_stdio(0);
	int NN = 1e5;
	f[1] = 1; f[2] = 2;
	for(int i=3;i<=NN;i++){
		f[i] = (f[i-1] + f[i-2]) % P;
	}
	
	cin>>s;
	N = s.length();
	s = "%" + s;
	
	LL ans = 1;
	for(int i=1;i<=N;i++){
		char c = s[i];
		if(c=='w' || c=='m'){
			cout<<"0"<<endl;
			return 0;
		}
		if(c!='n' && c!='u') continue;
		
		int n = 1;
		while(i+1<=N && s[i+1]==c){
			++n;
			++i;
		}
		
		ans = (ans * f[n]) % P;
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}