typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
char second[N];
int n;
ll fib[N];

int main() {



  fib[0] = fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  }

  scanf("%s", second);
  n = strlen(second);

  vector<int> g;
  for (int i = 0; i < n; i++) {
    if (second[i] == 'm' || second[i] == 'w') {
      cout << 0 << '\n';
      return 0;
    }
    if (i == 0) {
      if (second[i] == 'u' || second[i] == 'n') {
        g.push_back(1);
      }
    } else {
      if (second[i - 1] == second[i] && (second[i] == 'u' || second[i] == 'n')) {
        g.back()++;
      } else if (second[i] == 'u' || second[i] == 'n') {
        g.push_back(1);
      }
    }
  }


  ll ans = 1;
  for (int x : g) {
    ans = ans * fib[x] % mod;
  }
  cout << ans << '\n';

  return 0;
}
