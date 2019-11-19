#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  vector<long long> a(n);
  for(int i = 0; n > i; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  long long beg = 0;
  long long en = 0;
  if(n%2)en+=a[n/2];
  for(int i = 0; n/2 > i; i++){
    beg += a[i];
    en += a[n-i-1];
  }
  cout << (beg*beg)+(en*en) << endl;
}