    #include <bits/stdc++.h>

    #define MAX 10e15+1
    #define MIN 0
    #define MOD 998244353
    #define FOR(i, a, b)    for(int i=a;i<b;i++)
    using namespace std;
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<int> vi;
    typedef pair<ll,ll> pll;
    typedef pair<double,double> ii;
    typedef vector<pll> vpll;
    ll N; ll M; ll Q; ll T;
    vll vl;
    string s1,s2;
    vector<ll> cunt;
    int main() {
       cin>>N;
       ll ans=0;
       for(ll i=2;i*i<=N;i++)
       {
           if(N%i==0)
           {
              if(ans==0||ans==i)
              {
                  ans=i;
                  N/=i;
                  i=1;
              }
              else
              {
                  ans=1;
              }
           }
       }


       if(ans==0) {
           cout << N;
       }
       else if(N!=ans){cout<<1;}
       else cout<<ans;
    }

