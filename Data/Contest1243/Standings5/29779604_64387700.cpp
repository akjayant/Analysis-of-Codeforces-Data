#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define mod 1000000007
#define bitcount(x) __builtin_popcount(x)
#define all(v) (v).begin(), (v).end()
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * (long long)1 * b) % p; }

using namespace __gnu_pbds;
template<class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

bool check(int arr[],int arr2[])
{
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=arr2[i])return false;
    }
    return true;
}

void Onigiri()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int flag=0,ans=0;
    int c1[n],c2[n],pos1=-1,pos2=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
           { 
            if(pos1==-1)pos1=i;
            else if(pos2==-1)pos2=i;
            else{  cout<<"No";return;}
           }
    }

    if(pos1!=-1&&pos2!=-1)
    {
        swap(s[pos1],t[pos2]);
        if(s==t){cout<<"Yes";return;}
        swap(s[pos1],t[pos2]);
        swap(s[pos2],t[pos2]);
        if(s==t){cout<<"Yes";return;}
        else {
            cout<<"No";return;
        }
    }
    else if(pos1!=-1) {
        swap(s[pos1],t[pos1]);
        if(s==t){cout<<"Yes";return;}
        else {
            cout<<"No";return;
        }
    }

    
}

signed main()
{

ios_base::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        Onigiri();
        cout<<endl;
    }
    return 0;
}