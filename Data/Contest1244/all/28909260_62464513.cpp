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
int sufit(int a,int b)
{
    int ans=a/b;
    if (a%b!=0)ans++;
    return ans;
}
int main()
{
    BOOST;
    int t;
    cin>>t;
    for (int z=0;z<t;z++)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        if (sufit(a,c)+sufit(b,d)>k)
        {
            cout<<"-1\n";
        }
        else cout<<sufit(a,c)<<" "<<sufit(b,d)<<"\n";
    }

    return 0;
}
