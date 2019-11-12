#include<bits/stdc++.h> 
using namespace std;
 
#define ll long long int
#define absdiff(a,b) (a>b)?a-b:b-a
#define debug cout<<"debug";
#define mp make_pair 
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD  1000000007
#define ll_MAX 92233720368599
#define endl "\n"
ll fast_expo(ll x,ll p){if(p==0) return 1;
else if(p%2==0){ ll t=fast_expo(x,p/2)%MOD;return (t*t)%MOD;} else return (x*(fast_expo(x,p-1))%MOD)%MOD;}
ll gcd(ll a,ll b){if(a==0||b==0) return a+b;  else return gcd(b%a,a); }

int main(){
     ll q=1;
     for(ll x=0;x<q;++x){
          ll n;cin>>n;
          ll mat[n][n];
          ll curr=n*n;
          ll flag=0;
          for(ll i=0;i<n;++i){
               if(flag==0){
                    flag=1;
                    for(ll j=0;j<n;++j){
                         mat[j][i]=curr;
                         curr--;
                    }
               }
               else{
                    flag=0;
                    for(ll j=n-1;j>=0;--j){
                         mat[j][i]=curr;
                         curr--;
                    }
               }
          }

          for(ll i=0;i<n;++i){
               for(ll j=0;j<n;++j) cout<<mat[i][j]<<" ";
               cout<<endl;
          }
     }
     return 0;
}