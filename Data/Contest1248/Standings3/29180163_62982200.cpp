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
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      int s1=0,s2=0;
      sort(a,a+n);
      for(int i=0;i<n;i++) 
      {
        if(i>=n/2)
        {
          s1+=a[i];
        }
        else s2+=a[i];
      }
      cout<<s1*s1+s2*s2;
}
// I never lose. I either win or I learn