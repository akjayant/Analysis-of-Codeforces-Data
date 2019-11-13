#include <iostream>
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

ll n,m;
ll pw(ll nr,ll pt){
  if(pt==0)return 1;
  if(pt==1)return nr%MOD;
  if(pt%2){
    ll aux=pw(nr,pt-1);
    return (aux*nr)%MOD;
  }
  ll aux=pw(nr,pt/2);
  return (aux*aux)%MOD;
}

int main()
{
    cin>>n>>m;
    cout<<pw((MOD+pw(2,m)-1)%MOD,n)<<'\n';
    return 0;
}
