#include <iostream>
using namespace std;
#define MOD 1000000007
int main(){
  //2^n-2
  long long n,m;cin>>n>>m;
  long long ans = 0;
  long long fib[2] = {1,1};
  for(int i = 0; n-1 > i; i++){
    swap(fib[0],fib[1]);
    fib[1] = (fib[1]+fib[0])%MOD;
  }
  ans += fib[1];
  fib[0]=1;
  fib[1]=1;
  for(int i = 0; m-1 > i; i++){
    swap(fib[0],fib[1]);
    fib[1] = (fib[1]+fib[0])%MOD;
  }
  cout << ((fib[1]+ans-1LL)*2)%MOD << endl;
}