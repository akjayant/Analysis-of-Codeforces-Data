#include <iostream>
using namespace std;
int main(){
  long long q;cin>>q;
  for(int i = 0; q > i; i++){
    long long n;cin>>n;
    long long z[2] = {0,0};
    for(int j = 0; n > j; j++){
      long long tmp;cin>>tmp;
      z[tmp%2]++;
    }
    long long m;cin>>m;
    long long x[2] = {0,0};
    for(int j = 0; m > j; j++){
      long long tmp;cin>>tmp;
      x[tmp%2]++;
    }
    cout << (long long)z[0]*x[0]+z[1]*x[1] << endl;
  }
}