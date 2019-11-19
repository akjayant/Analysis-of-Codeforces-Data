#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;

const ll inf=1e18;
const int maxn=1e5+5;
vector<int>g[maxn];


int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		a=a/c+(a%c!=0);
		b=b/d+(b%d!=0);
		if(a+b>k)printf("-1\n");
		else printf("%lld %lld\n",a,b);
	}
	return 0;
} 
 