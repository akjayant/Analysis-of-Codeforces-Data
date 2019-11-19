#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 100007;

int n, a[N];
long long k, ps[N];

bool check(int diff) {
  int i, j;

  for(i=1, j=1;i<=n;i++) {
    while(j<n && a[j + 1] - a[i]<=diff) {
      ++j;
    }
  
    long long cost = (a[i] * 1ll * (i - 1) - ps[i - 1]) + ((ps[n] - ps[j]) - (a[i] + diff) * 1ll * (n - j));

    if(cost<=k) return true;
  }

  for(j=n, i=n;j>=1;j--) {
    while(i>1 && a[j] - a[i - 1]<=diff) {
      --i;
    }

    long long cost = ((a[j] - diff) * 1ll * (i - 1) - ps[i - 1]) + ((ps[n] - ps[j]) - a[j] * 1ll * (n - j));

    if(cost<=k) return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, left, right, middle;

  cin>>n>>k;
  for(i=1;i<=n;i++) {
    cin>>a[i];
  }
  sort(a + 1, a + 1 + n);
  for(i=1;i<=n;i++) {
    ps[i] = ps[i - 1] + a[i];
  }

  left = -1;
  right = 1000000000;

  while(right-left>1) {
    middle = (left + right) / 2;
    
    if(check(middle)) {
      right = middle;
    } else {
      left = middle;
    }
  }

  cout<<right<<endl;

  return 0;
}
