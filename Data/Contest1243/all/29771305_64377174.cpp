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
      fr(i,0,n){
        if(s[i]!=t[i]){
          if(k==0)
          j=i;
          else if(k==1)
          l=i;
          k++;
        }
      }
  //    cout<<k<<" ";
      if(k!=2&&k!=0)
      cout<<"No\n";
      else if(k==0)
      cout<<"Yes\n";
      else{
      //  cout<<s[j]<<" "<<s[l]<<" "<<t[j]<<" "<<t[l];
        if(s[j]==s[l]&&t[j]==t[l])
        cout<<"Yes\n";
        else
        cout<<"No\n";
      }
    }

    return 0;
}
