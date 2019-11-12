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
vector<char> ch1;
vector<char> ch2;
int32_t main(){
        getFaster;
        int t;
        cin>>t;
        rep(ii,0,t)
        {
           int n;
           cin>>n;
           string s,t;
           cin>>s>>t;
           ch1.clear();ch2.clear();
           int cnt1[26]={0},cnt2[26]={0};
           rep(i,0,s.length()){cnt1[s[i]-'a']++;ch1.push_back(s[i]);}
           rep(i,0,n){cnt2[t[i]-'a']++;ch2.push_back(t[i]);}
           bool stop=false;
           rep(i,0,26)
           {
               cnt1[i]+=cnt2[i];
               if(cnt1[i]&1)
               {
                stop=true;
                break;
               } 
           }
           if(stop)
           {
              cout<<"No"<<endl;
              continue;
           }
           cout<<"Yes"<<endl;
           vector<pii> ans;
           rep(i,0,n)
           {
              char x=ch1[i];
              int ind=-1;
              if(x==ch2[i])continue;
              rep(j,i+1,n)
              {
                  if(x==ch1[j])
                  {
                     ind=j;
                     break;
                  }  
              }
              if(ind!=-1)
              {
                  char t1=ch2[i];
                  char t2=ch1[ind];
                  ch1[ind]=t1;
                  ch2[i]=t2;
                  ans.push_back({ind+1,i+1});
                  continue;
              }
              rep(j,i+1,n)
              {
                  if(x==ch2[j])
                  {
                     ind=j;
                     break;
                  }  
              }
              char t1=ch2[i];
              char t2=ch1[n-1];
              char t3=ch2[ind];
              ans.push_back({n,ind+1});
              ans.push_back({n,i+1});
              ch2[i]=t3;
              ch1[n-1]=t1;
              ch2[ind]=t2;  
           }
           cout<<ans.size()<<endl;
           rep(i,0,ans.size())
           {
            cout<<ans[i].f<<" "<<ans[i].s<<endl;
           } 
        }  
        return 0;
}