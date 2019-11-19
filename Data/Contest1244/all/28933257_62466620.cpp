#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,a,b,c,d,k;
    cin >> t;
    while(t--)
    {
    	cin >> a >> b >> c >> d >> k;
    	ll p=a/c;
    	if(a%c!=0)
    		p++;
    	ll pp=b/d;
    	if(b%d!=0)
    		pp++;
    	if(p+pp<=k)
    		cout << p << " " << pp << endl;
    	else
    		cout << -1 << endl;
    }

	return 0;
}