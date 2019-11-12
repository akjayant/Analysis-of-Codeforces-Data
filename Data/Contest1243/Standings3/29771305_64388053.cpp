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
int main()
{
    flash
    #ifndef ONLINE_JUDGE
    freopen("inp","r",stdin);
    #endif

    tc{
      ll n,i,j,k=0,l;
      cin>>n;
      string s,t;
      cin>>s>>t;
      ll a[26]={0};
      fr(i,0,n){
        a[s[i]-'a']++;
        a[t[i]-'a']++;
      }
      fr(i,0,26){
        if(a[i]%2!=0)
        k=1;
      }
      if(k==1){
        cout<<"No\n";
        continue;
      }
      else
      cout<<"Yes\n";
      vp v,q;
      vl r;
      k=-1;
      fr(i,0,26){
        r.clear();
        fr(j,0,n){
          if(s[j]=='a'+i&&s[j]!=t[j]){
            r.pb(j);
          }
        }
        if(r.size()%2==1){
          v.pb({r[0],r[0]});
          swap(s[r[0]],t[r[0]]);
          l=r.size();
          for(j=1;j<l;j+=2){
            v.pb({r[j],r[j+1]});
            swap(s[r[j]],t[r[j+1]]);
          }
        }
        else{
          l=r.size();
          for(j=0;j<l;j+=2){
            v.pb({r[j],r[j+1]});
            swap(s[r[j]],t[r[j+1]]);
          }
        }


        r.clear();
        fr(j,0,n){
          if(t[j]=='a'+i&&s[j]!=t[j]){
            r.pb(j);
          }
        }
        l=r.size();
        for(j=0;j<l;j+=2){
          v.pb({r[j],r[j+1]});
          swap(s[r[j]],t[r[j+1]]);
        }
      }
      k=v.size();
      cout<<k<<endl;
      for(auto p:v){
        cout<<p.F+1<<" "<<p.S+1<<endl;
      }
    }

    return 0;
}
