#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m=1e9+7;
ll fib[200000];
void init()
{
    fib[1]=1;fib[2]=2;
    for(int i=3;i<200000;i++)
        fib[i]=(fib[i-1] + fib[i-2])%m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    ll t;
    t=1;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=s.length();
       vector<ll> arr;
       ll i=1;
       map<char,int> mp;
       for(int i=0;i<n;i++)
        mp[s[i]]++;
       while(i<n)
       {
           ll cnt=1;
           while(i<n && s[i]==s[i-1])
           {
               i++;cnt++;
           }
           if(s[i-1]=='u' || s[i-1]=='n')
            arr.push_back(cnt);
           i++;
       }
       ll ans=1;
       if(mp['m']>0 || mp['w']>0)
       {
           cout<<0;
           continue;       }
       for(int i=0;i<arr.size();i++)
        ans=(ans%m * fib[arr[i]]%m)%m;
       cout<<ans;
    }
}
