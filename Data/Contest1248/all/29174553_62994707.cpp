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

const int N=1e5+7;
const int inf=1e18+5;
const int mod=1e9+7;
const ld eps=1e-9;

int ans=0;
int n,m;
int dp[N][2][2];

void upd(int& x)
{
    if (x>=mod)x-=mod;
}

int st(int n,int k)
{
    int ans=1;
    while(k){
        if (k%2==1){
            ans=(ans*n)%mod;
        }
        n=(n*n)%mod;
        k/=2;
    }
    return ans;
}

main ()
{
    ios;
    int n,m;
    cin>>n>>m;
    int ans=0;
    dp[1][0][0]=1;
    dp[1][1][0]=1;
    for (int i=1;i<max(n,m);++i){
        for (int t=0;t<=1;++t){
            for (int kol=0;kol<=1;++kol){
                if (kol==0){
                    dp[i+1][t][1]+=dp[i][t][kol];
                    upd(dp[i+1][t][1]);
                }
                dp[i+1][t^1][0]+=dp[i][t][kol];
                upd(dp[i+1][t^1][0]);
            }
        }
    }
    for (int t=0;t<=1;++t){
        for (int kol=0;kol<=1;++kol){
            ans+=dp[n][t][kol];
            upd(ans);
        }
    }
    for (int t=0;t<=1;++t){
        for (int kol=0;kol<=1;++kol){
            ans+=dp[m][t][kol];
            upd(ans);
        }
    }
    ans=(ans+mod-2)%mod;
    cout<<ans<<endl;
}
