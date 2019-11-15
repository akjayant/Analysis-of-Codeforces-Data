#include<bits/stdc++.h>
#define int long long int
#define ull unsigned long long int
#define getFaster ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define rev(i,n,init) for(int i=n;i>=init;i--)
#define MAXN 200005
#define MOD 1000000007
#define f first
#define s second
#define endl '\n'
#define pii pair<int,int>
#define precise(i) cout<<fixed<<setprecision(i)
using namespace std;
const double PI = atan(1.0)*4;
const int64_t INF=100000000000000003;
const int32_t LOG=21;
const int BIG=pow(2,20);
int32_t main(){
        getFaster;
         int n1;
         cin>>n1;
         rep(ii,0,n1)
         {
           int n;
           cin>>n;
           string s,t;
           cin>>s>>t;
           int cnt=0;
           vector<int> v;
           int cnt1=0;
           rep(i,0,s.length())
           {
              if(s[i]!=t[i])
              {cnt++;v.push_back(i);}
              else if(s[i]==t[i])
              cnt1++;  
           }
           if(cnt==2 && s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]])cout<<"Yes"<<endl;
           else cout<<"No"<<endl;
         }
          return 0;
}