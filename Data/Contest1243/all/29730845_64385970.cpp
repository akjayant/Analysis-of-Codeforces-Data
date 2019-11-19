#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
const int mx=2e5+10;

ll n,m;
vector<ll>s;

int main(){
	scanf("%lld",&n);
	if(n==1)
	printf("1\n");
	else{
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			s.push_back(i);
			while(n%i==0)
			n/=i;
		}
	}
	if(n!=1) s.push_back(n);
	if(s.size()>1)
	printf("1\n");
	else
	printf("%lld\n",s[0]);
    }
	return 0;
}