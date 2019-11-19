#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fr(i,j,n) for(i=j;i<n;i++)
#define frd(i,j,n) for(i=n-1;i>=j;i--)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL),cout.tie(NULL);
#define tc int tc; cin>>tc; while(tc--)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define vc vector
#define vl vector<ll>
#define pr pair<ll,ll>
#define vp vector<pr>
#define pqmx priority_queue <ll>
#define pqmn priority_queue <ll,vector<ll>,greater<int>()>
#define all(v) v.begin(),v.end()
#define srt(v) sort(all(v))
#define srtd(v) sort(v.rbegin(),v.rend())
#define F first
#define S second
const ll N=1000005;
ll isprime[N+100]={0};
void seive()
{
    for (ll p=2; p*p<=N; p++)
    {
        if (isprime[p] == 0)
        {
	    for (ll i=p*p; i<=N; i += p)
                isprime[i] = 1;
        }
    }
}
int main()
{
    flash
    #ifndef ONLINE_JUDGE
    freopen("inp","r",stdin);
    #endif
    seive();
    ll n,i,j,k=0;
    vl v;
    cin>>n;
    ll m=n;
    for(i=2;i<=sqrt(m);i++){
      if(n%i==0){
        v.pb(i);
        while(n%i==0)
        n/=i;
      }
    }
    if(n!=1)
    v.pb(n);
    k=v.size();
    if(k==1)
    cout<<v[0];
    else
    cout<<1;
    return 0;
}
