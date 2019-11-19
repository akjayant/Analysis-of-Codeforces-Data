#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define maxn 100111
#define ll long long 
#define ull unsigned long long 
const ll mod = 1e9+7;

ll qpow(ll a,ll n){
	ll ret = 1LL;
	while(n){
		ret = n&1LL?ret*a%mod:ret;
		n >>= 1;
		a = a*a%mod;
	}
	return ret;
}

int kleft[600],kright[600];
char s[600];
int n;

int work(){
	int cntl = 0,cntr = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			cntl+=1;
			kleft[i] = -1;
		}else{
			if(cntl>0){
				cntl--;
				kleft[i] = cntl==0?cntr:-1;
			}else{
				cntr++;
				kleft[i] = cntr;
			}
		}
	}

	cntl = cntr = 0;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='('){
			if(cntr>0){
				cntr--;
				kright[i] = cntr==0?cntl:-1;
			}else{
				cntl++;
				kright[i] = cntl;
			}
		}else{
			cntr++;
			kright[i] = -1;
		}
	}

	int rs = kleft[n-1]==0?1:0;
	for(int i=1;i<n;i++){
		rs += kright[n-i]==kleft[n-i-1] && kleft[n-i-1]>=0;
	}
	return rs;
}

int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	while(cin>>n){
		cin>>s;
		int ans = work();
		int l=0,r=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(s[i]==s[j])continue;
				swap(s[i],s[j]);
				int tmp = work();
				if(tmp>ans){
					ans = tmp;
					l = i;r = j;
				}
				swap(s[i],s[j]);
			}
		}

		cout<<ans<<endl;
		l++;r++;
		if(l>r)swap(l,r);
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}