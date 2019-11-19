#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+20;
int n;
ll arr[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr,arr+n);
  ll l0=0,l1=0;
  for (int i = 0,j = n - 1,o=0; i <= j;o++) {
    if(o&1){
      l1+=arr[i++];
    }
    else l0+=arr[j--];
  }
  cout << l0*l0+l1*l1 << endl;
}