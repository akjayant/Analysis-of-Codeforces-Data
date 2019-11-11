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

char s[N];
int l[N];
int n;
int a[4];
int a1[4];
int a2[4];
int a3[4];

pair<int,int> func(int i)
{
    if (i==1)return {1,1};
    if (i==2)return {1,2};
    if (i==3)return {1,3};
    if (i==4)return {2,1};
    if (i==5)return {2,2};
    if (i==6)return {2,3};
    if (i==7)return {3,1};
    if (i==8)return {3,2};
    if (i==9)return {3,3};
}

int ans[N];

char sym(int j)
{
    if (j==1){
        return 'R';
    }
    if (j==2){
        return 'S';
    }
    if (j==3){
        return 'P';
    }
}

main ()
{
    ios;
    int t;
    cin>>t;
    for (int tt=1;tt<=t;++tt){
        cin>>n;
        cin>>a[1]>>a[2]>>a[3];
        swap(a[2],a[3]);
        for (int i=1;i<=n;++i){
            cin>>s[i];
            if (s[i]=='R')l[i]=1;
            else if (s[i]=='S')l[i]=2;
            else l[i]=3;
        }
        for (int i=1;i<=n;++i)ans[i]=0;
        int cnt=0;
        for (int i=1;i<=n;++i){
            if (l[i]==2){
                if (a[1]){
                    --a[1];
                    ++cnt;
                    ans[i]=1;
                }
            }
        }
        for (int i=1;i<=n;++i){
            if (l[i]==1){
                if (a[3]){
                    --a[3];
                    ++cnt;
                    ans[i]=3;
                }
            }
        }
        for (int i=1;i<=n;++i){
            if (l[i]==3){
                if (a[2]){
                    --a[2];
                    ++cnt;
                    ans[i]=2;
                }
            }
        }
        if (cnt>=(n+1)/2){
            cout<<"YES"<<endl;
            for (int i=1;i<=n;++i){
                if (!ans[i]){
                    for (int j=1;j<=3;++j){
                        if (a[j]){
                            --a[j];
                            ans[i]=j;
                            break;
                        }
                    }
                }
                cout<<sym(ans[i]);
            }
        }
        else {
            cout<<"NO";
        }
        cout<<endl;
    }
}
