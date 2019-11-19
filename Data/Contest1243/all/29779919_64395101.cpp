#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin>>n;
  vector<ll> prime_fact;
  if(n%2==0) prime_fact.pb(2);
  while(n%2==0){
    n=n/2;
  }
  for(int i=3;i<=sqrt(n);i=i+2){
    if(n%i==0) prime_fact.pb(i);
    while(n%i==0){
      n=n/i;
    }
  }
  if(n>2) prime_fact.pb(n);
  if(prime_fact.size()==1){
    cout<<prime_fact[0]<<"\n";
  }
  else{
    cout<<"1\n";
  }
}
