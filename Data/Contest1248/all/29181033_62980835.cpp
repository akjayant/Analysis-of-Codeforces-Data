#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define war(i,s,n) for(long long i=s;i<n;i++)
#define pb push_back
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fr first
#define sc second
#define mod 1000000007
#define vctr2d vector<vector<long long>>
#define vctr vector<long long>
#define pll pair<long long,long long>
#define rz(n) resize(n)
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mod2  998244353
#define arrin(a,n) for(int i = 0; i < n ; i++){cin>>a[i];}
#define arrout(a,n) for(int i = 0;i < n; i++){cout<<a[i]<<" ";}
#define ex(s) cout<<s<<endl;exit(0);
#define itr iterator
#define tra(it,m) for(it=m.begin();it!=m.end();++it)
//___________________________________________________________________________________________________________________________________________________________
int main()
{
          ll n;
          cin>>n;
          ll a[n];
          arrin(a,n);
          sort(a,a+n);
          int xx = n/2;
          ll sum = 0;
          war(i,0,xx)
          {
                    sum += a[i];
          }
          sum *= sum;
          ll sum1 = 0;
          war(i,xx,n)
          {
                    sum1 += a[i];
          }
          sum1 *= sum1;
          cout<<sum+sum1<<endl;

}
