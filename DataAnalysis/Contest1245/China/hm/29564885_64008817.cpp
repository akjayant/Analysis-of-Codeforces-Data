using namespace std;

const long long maxn = 100010;
const long long Mod = 1e9 + 7;

long long n, ans = 1, fac[maxn], inv[maxn];
char s[maxn];

inline long long power(long long a, long long b)
{
 long long r = 1;
 while ( b ) { if ( b & 1 ) r = r * a % Mod; a = a * a % Mod; b >>= 1; }
 return r;
}

inline long long Solve(long long x)
{
 long long ret = 1, last = 1;
 for ( long long i = (2), _end_ = (x); i <= _end_; ++ i ) { long long p = ret; ret = (ret + last) % Mod; last = p; }
 return ret;
}

signed main()
{

 freopen("input.txt", "r",stdin);
 freopen("output.txt", "w",stdout);

 scanf("%s", s + 1);
 n = strlen(s + 1);
 fac[0] = inv[0] = 1; for ( long long i = (1), _end_ = (n); i <= _end_; ++ i ) fac[i] = fac[i - 1] * i % Mod;
 inv[n] = power(fac[n], Mod - 2); for ( long long i = n - 1; i >= 1; -- i ) inv[i] = inv[i + 1] * (i + 1) % Mod;
 for ( long long i = 1; i <= n; ++ i )
 {
  if ( s[i] == 'm' || s[i] == 'w' ) { puts("0"); return 0; }
  if ( s[i] != 'u' && s[i] != 'n' ) continue ;
  long long j = i;
  while ( s[i] == s[j] && (s[j] == 'u' || s[j] == 'n') ) ++ j;
  -- j; ans = ans * Solve(j - i + 1) % Mod;
  i = j;
 }
 cout << ans << endl;
 return 0;
}
