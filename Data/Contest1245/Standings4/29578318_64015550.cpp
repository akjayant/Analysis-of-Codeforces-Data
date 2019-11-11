#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define endl '\n'
#define y1 yaumru
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter vector<int>::iterator
#define int long long
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

//find_by_order
//order_of_key

const int N=3e5+7;
const int inf=1e18+5;
const int mod=1e9+7;
const ld eps=1e-9;

int dp[N];
char s[N];

void update(int& x)
{
    if (x>=mod)x-=mod;
}

main ()
{
    ios;
    string l;
    cin>>l;
    int n=l.size();
    for (int i=0;i<l.size();++i)s[i+1]=l[i];
    dp[0]=1;
    for (int i=1;i<=n;++i){
        if (s[i]=='w'){
            cout<<0<<endl;
            exit(0);
        }
        if (s[i]=='m'){
            cout<<0<<endl;
            exit(0);
        }
    }
    for (int i=1;i<=n;++i){
        if (s[i]=='u'){
            dp[i]=dp[i-1];
            if (s[i-1]=='u'){
                dp[i]+=dp[i-2];
            }
            update(dp[i]);
        }
        else if (s[i]=='n'){
            dp[i]=dp[i-1];
            if (s[i-1]=='n'){
                dp[i]+=dp[i-2];
            }
            update(dp[i]);
        }
        else {
            dp[i]=dp[i-1];
        }
    }
   // cout<<dp[1]<<endl;
    cout<<dp[n]<<endl;
}
