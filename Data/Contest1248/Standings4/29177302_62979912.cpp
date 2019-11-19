#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define sscc ios::sync_with_stdio(false);cin.tie(0);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

int main()
{
	sscc;
	ll t,n,m,x;
	cin>>t;
	while(t--){
		cin>>n;
		ll la=0,lb=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x%2==0)	la++;
			else	lb++;
		}
		cin>>m;
		ll ra=0,rb=0;
		for(int i=1;i<=m;i++){
			cin>>x;
			if(x%2==0)	ra++;
			else	rb++;
		}
		cout<<(la*ra+lb*rb)<<endl;
	}
	return 0;
}

