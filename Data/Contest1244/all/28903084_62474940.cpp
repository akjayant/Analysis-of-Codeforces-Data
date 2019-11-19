#include<bits/stdc++.h>
#define bclz(x) (__builtin_clz(x))
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int,int> pii;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		bool fl=1;
		for(int i=1;i<k;i++){
			if(i*c>=a and (k-i)*d>=b){
				cout<<i<<' '<<k-i<<endl;
				fl=0;
				break;
			}
		}
		if(fl) cout<<"-1"<<endl;
	}
	
	
	return 0;
}
      