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

char a[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>a;
		int lb=-1,rb=-1;
		for(int i=0;i<n;i++){
			if(lb==-1&&a[i]=='1'){
				lb=i;
			}
			if(a[i]=='1'){
				rb=i;
			}
		}
		if(lb==rb&&rb==-1){
			cout<<n<<endl;
		}
		else{
			cout<<max(rb*2+2,(n-lb)*2)<<endl;
		}
	}
	return 0;
}

