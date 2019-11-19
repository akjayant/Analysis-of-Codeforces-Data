#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1;}return res%p;}
const int N=303;
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      // freopen("output.txt","w",stdout);
      #endif
      int t;
      cin>>t;
      while(t--)
      {
        int n;
        cin>>n;
        int ev1=0,od1=0,ev2=0,od2=0;
        for(int i=0;i<n;i++)
        {
          int x;
          cin>>x;
          if(x%2==0) ev1++;
          else od1++;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
          int x;
          cin>>x;
          if(x%2==0) ev2++;
          else od2++;
        }
        cout<<ev1*ev2+od1*od2<<"\n";
      }
}
// I never lose. I either win or I learn