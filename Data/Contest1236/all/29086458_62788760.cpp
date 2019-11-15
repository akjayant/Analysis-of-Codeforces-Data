#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define FF first
#define SS second
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
typedef pair<int,int> PII;
const int MAX = 2e5 + 5;
int n,a,b,c,nc,nb;
ll ans;
int main() {
	cin>>n;
	while(n--) {
		cin>>a>>b>>c;
		ans=0;nc=c/2;
		if(nc<=b) ans+=nc*3,b-=nc;
		else ans+=b+b*2,b=0;
		nb=b/2;
		if(nb<=a) ans+=nb*3,a-=nb;			
		else ans+=a+a*2,a=0;
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}