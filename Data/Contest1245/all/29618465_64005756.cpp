#include <bits/stdc++.h>
#include <string.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define MAXN        200001
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll int n=s.length();
    ll int count1=0;
    ll int count2=0;
    vector <ll int> ans;
    ll int f1=0;
    rep(i,0,n)
    {
        if (s[i]=='u') count1=count1+1;
        else {if (count1>1) ans.push_back(count1);count1=0;}
        if (s[i]=='n') count2=count2+1;
        else {if (count2>1) ans.push_back(count2);count2=0;}
        if (s[i]=='m' or s[i]=='w')
        {
            cout << 0 << endl;
            exit(0);
        }
    }
    if (count1>1) ans.push_back(count1);
    if (count2>1) ans.push_back(count2);
    ll int ans1=1;
    ll int value[100001];
    value[1]=1;
    value[2]=2;
    rep(i,3,100001) value[i]=(value[i-1]+value[i-2])%hell;
    for (auto it: ans)
    {
        ans1=(ans1*(value[it]))%hell;
    }
    cout << ans1 << endl;
}