using namespace std;

typedef long long ll;

const int N = 1e5+2;
const int MOD = 1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);







  vector<int> fibo(N);
  fibo[0] = 1; fibo[1] = 1;
  for(int i = 2; i < N; i++) {
    fibo[i] = (fibo[i-1] + fibo[i-2])%MOD;
  }


  string s;
  while(cin >> s) {
    if(s.find('w') != -1 || s.find('m') != -1) cout << "0" << '\n';
    else {
      s.push_back('.');
      int ans = 1;
      int cnt = 0;
      for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'n' || s[i] == 'u') {

          if(i == 0 || s[i] == s[i-1]) cnt++;
          else {

            ans = (1ll * ans * fibo[cnt]) % MOD;
            cnt = 1;
          }
        } else {
          ans = (1ll * ans * fibo[cnt]) % MOD;
          cnt = 0;
        }

      }
      cout << ans << '\n';
    }
  }


}
