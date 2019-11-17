using namespace std;
const int N = 1e5 + 3, MOD = 1e9 + 7;
int n, mem[N];
char s[N];
int go(int i) {
 if (i + 1 >= n)
  return 1;
 int &ret = mem[i];
 if (~ret)
  return ret;
 ret = go(i + 1);
 if (s[i] == 'u' && s[i + 1] == 'u')
  ret = (ret + go(i + 2)) % MOD;
 if (s[i] == 'n' && s[i + 1] == 'n')
  ret = (ret + go(i + 2)) % MOD;
 return ret;
}
int main() {

 freopen("input.in", "r",
# 22 "../Data/Contest1245/all/29598375_64007172.cpp" 3 4
                         stdin
# 22 "../Data/Contest1245/all/29598375_64007172.cpp"
                              );

 scanf("%s", s);
 n = strlen(s);
 for (int i = 0; i < n; ++i) {
  if (s[i] == 'm' || s[i] == 'w') {
   puts("0");
   return 0;
  }
 }
 memset(mem, -1, sizeof mem);
 printf("%d\n", go(0));
 return 0;
}
