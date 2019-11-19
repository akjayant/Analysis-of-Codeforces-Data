//mridul1809
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define p(x) printf("%d ",x)
#define pl(x) printf("%lld ",x)
#define pd(x) printf("%lf ",x)
#define ps(x) printf(x)
#define pend printf("\n")
#define nm 100005
string s;
int main()
{
	int t,i;
	cin >> t;
	while(t--)
	{
		int n ;
		cin >> n;
		int ans = n;
		cin >> s;

		for(i=0;i<s.size();i++)
		{
			if(s[i] == '0')
				continue;

			ans = max(ans , 2*max(i+1 , n-i));
		}

		cout << ans << endl;
	}	
	return 0;
}