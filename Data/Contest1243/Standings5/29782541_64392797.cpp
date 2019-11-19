#include <iostream>
#include <vector>
using namespace std;
long long gcd(long long a, long long b){
  if(a%b)return gcd(b,a%b);
  else return b;
}
long long prime_search(long long n){
  vector<long long > a;
  for(long long i = 2; n >= i*i; i++){
    if(!(n%i)){
      a.push_back(i);
      a.push_back(n/i);
    }
  }
  if(a.empty())return n;
  long long ans = a[0];
  for(int i = 1; a.size() > i; i++){
    ans = gcd(ans,a[i]);
  }
  return ans;
}
int main(){
  long long n;cin>>n;
  cout << prime_search(n) << endl;
}