#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll a[maxn],n,k,cnt=0;
int main(){
	cin>>n;
	ll mem=n;
	bool flg=1;
	for(ll i=2;i*i<=n;i++){
		if (n%i==0){
			if (flg==0){
				cout<<"1"<<endl;
				return 0;
			}
			while(n!=1){
				if (n%i!=0) break;
				n/=i;
			}
			if (n==1){
				cout<<i<<endl;
				return 0;
			}
			flg=0;
		}
	}
	if (mem!=n) cout<<"1"<<endl;
	else cout<<n<<endl;
}