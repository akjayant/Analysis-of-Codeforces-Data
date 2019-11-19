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
ll a,b,c,d,k;
int main()
{
	int T;
	cin>>T;
	while(T--) {
		cin>>a>>b>>c>>d>>k;
		ll tmp1 = ceil(a*1.0/c);
		ll tmp2 = ceil(b*1.0/d);
		if(tmp1 + tmp2 > k) {
			puts("-1");
		}
		else {
			printf("%lld %lld\n",tmp1,k-tmp1);
		}
		
	} 


	return 0 ;
}
