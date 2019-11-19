#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define pa pair<ll,int>
#define ld long double
#define st first
#define nd second
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

int main()
{
    BOOST;
    int t;
    cin>>t;
    for (int z=0;z<t;z++)
    {
       int n;
       cin>>n;
       string s;
       cin>>s;
       int maxipos=-1,minipos=-1;
       for (int i=0;i<s.length();i++)if(s[i]=='1')maxipos=i;
       for (int i=s.length()-1;i>=0;i--) if (s[i]=='1')minipos=i;
        int ans=0;
        ans=max(ans,n);
       if (maxipos!=-1)
       {
           ans=max(ans,maxipos+1+max(maxipos+1,n-maxipos));
           ans=max(ans,n-minipos+max(minipos+1,n-minipos));
       }
       cout<<ans<<"\n";
    }
    return 0;
}
