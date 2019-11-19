#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef complex<double> cp;

const int maxn=(int)3e5+9;
const ll mod=(ll)1e9+7;
const db pi=acos(-1);
const db eps=1e-15;

#define dbg(x) cerr<<#x<<" is "<<x<<endl;

int main(){
	int a,b,c,d,k;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>k;
		int t=(a+c-1)/c;
		if((k-t)*d>=b){
			cout<<t<<' '<<k-t<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}

