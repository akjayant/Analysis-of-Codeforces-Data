#include<bits/stdc++.h>
typedef long long ll;

#define pb push_back
#define mp make_pair
#define mod 1000000007
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>str;
    ll n = str.size();
    
    ll ans = 1;
    ll dp[n+1] = {0};
    dp[1] = 1;
    dp[0] = 1;
    for(ll i=2;i<=n;i++){
        dp[i] = (dp[i-2] + dp[i-1])%mod;
    }

        ll i=0;
    while(i<n){
        if(str[i]=='u')
        {
            ll j = i;
            ll ct=0;
            while(j < n && str[j]==str[i])
                {ct++;j++;}
            if(ct==1)
                {i++;continue;}

            ans = (ans*(dp[ct]))%mod;
            i=j;
        }
        else if(str[i]=='n'){
            ll j = i;
            ll ct=0;
            while(j < n && str[j]==str[i])
                {ct++;j++;}
            if(ct==1)
                {i++;continue;}

            ans = (ans*(dp[ct]))%mod;
            i=j;
        }
        else if(str[i]=='m' || str[i]=='w'){
            ans = 0;break;
            i++;
        }
        else
            i++;
    }
    cout<<ans;
    return 0;
    
}