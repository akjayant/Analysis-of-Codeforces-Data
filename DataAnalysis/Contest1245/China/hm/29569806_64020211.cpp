using namespace std;

typedef long long LL;
const int mod = 1000000007;
const int maxn = 200000 + 7;

int fib[maxn];
char str[maxn];
vector<int> vec;

int main() {
 fib[0] = fib[1] = 1;
 for(int i = 2; i < maxn; ++i) {
  fib[i] = (fib[i-1] + fib[i-2]) % mod;
 }
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    int flag = 1;
    for(int i = 1; i <= n; ++i) {
     if(str[i] == 'm' || str[i] == 'w') {
      flag = 0;
      break;
     }
    }
    if(!flag) return printf("0\n") * 0;
    for(int i = 1; i <= n; ++i) {
     if(str[i] != 'u' && str[i] != 'n') continue;
     int cnt = 0;
     if(str[i] == 'n') {
      while(i <= n && str[i] == 'n') {
       ++cnt;
       ++i;
      }
      --i;
      vec.push_back(cnt);
     } else {
      while(i <= n && str[i] == 'u') {
       ++cnt;
       ++i;
      }
      --i;
      vec.push_back(cnt);
     }
    }
    LL ans = 1;
    for(auto x : vec) {
     ans = ans * fib[x] % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
