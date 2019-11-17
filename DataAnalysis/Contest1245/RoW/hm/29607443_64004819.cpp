using namespace std;


const int MOD = 1e9 + 7;

inline int sum(int a, int b){
 if (a + b < 0)
  return (a + b + MOD) % MOD;
 return (a + b) % MOD;
}

inline void add(int &a, int b){
 a = sum(a, b);
}

const int N = 2e5 + 10;

string s;
int memo[N], n;

int dp(int x){
 if (x == n)
  return 1;
 int &ret = memo[x];
 if (~ret)
  return ret;
 ret = dp(x + 1);
 if (x + 1 == n)
  return ret;
 if (s[x] == s[x + 1] && (s[x] == 'u' || s[x] == 'n'))
  add(ret, dp(x + 2));
 return ret;
}

int main () {
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);

 cin >> s;
 memset(memo, -1, sizeof memo);
 n = (int)s.size();
 for (auto &x : s)
  if (x == 'm' || x == 'w'){
   cout << 0 << '\n';
   return 0;
  }
 cout << dp(0) << '\n';

 return 0;
}
