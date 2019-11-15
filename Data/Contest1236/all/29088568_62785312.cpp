#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int ans=0;
		int k = min(c/2,b);
		ans+= (k + 2*k);
		b-=k;
		k = min(b/2,a);
		ans+= (k + 2*k);
		cout<<ans<<endl;
	}
	return 0;
}