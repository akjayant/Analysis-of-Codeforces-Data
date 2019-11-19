#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
char a[1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n;
    cin >> t;
    while(t--)
    {
        cin >> n ;
        cin >> a;
        ll r=-1,l=-1;
        for(ll i=0;i<n;i++)
        {
            if(a[i]=='1')
                r=i;
            if(a[n-i-1]=='1')
                l=n-i-1;
        }
        ll ans1 = (r+1)*2;
        ll ans2 = (n-l)*2;
        if(l==-1)
        ans2=n;    
        cout << max(ans1,ans2) << endl;
    }



	return 0;
}