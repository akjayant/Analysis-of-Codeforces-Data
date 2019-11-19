#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> input;
long long bot, top;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  input.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }

  sort(input.begin(), input.end());
  for (int i = 0; i < n / 2; ++i) {
    bot += input[i];
  }
  for (int i = n / 2; i < input.size(); ++i) {
    top += input[i];
  }

  cout << bot * bot + top * top << endl;

  return 0;
}
