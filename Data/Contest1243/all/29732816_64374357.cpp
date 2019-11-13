/*================= *\
|  ID : aman__guta__ |
|      LANG: C++     |
\*==================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define fs first
#define sc second 
#define mod 1000000007
#define JOKER ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
int fib[100010];
main()
{
    JOKER
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);
        int ans=-1;
        int b=INT_MAX;
        for(int i=n-1; i>=0; i--)
        {
            ans=max(ans,min(n-i,a[i]));
        }
        cout<<ans<<endl;
    }
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}