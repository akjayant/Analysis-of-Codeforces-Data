using namespace std;

typedef long long ll;

using ll = long long;
ll modinv(ll a, ll m) {
(static_cast <bool> (m > 0) ? void (0) : __assert_fail ("m > 0",  __extension__ __PRETTY_FUNCTION__));
 if (m == 1) return 0;
 a %= m;
 if (a < 0) a += m;

(static_cast <bool> (a != 0) ? void (0) : __assert_fail ("a != 0", __extension__ __PRETTY_FUNCTION__));
 if (a == 1) return 1;
 return m - modinv(m, a) * m / a;
}

template <int MOD_> struct modnum {
private:
 int v;
public:
 static const int MOD = MOD_;

 modnum() : v(0) {}
 modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
 explicit operator int () const { return v; }
 friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
 friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

 modnum operator ~ () const {
  modnum res;
  res.v = modinv(v, MOD);
  return res;
 }

 modnum& operator += (const modnum& o) {
  v += o.v;
  if (v >= MOD) v -= MOD;
  return *this;
 }
 modnum& operator -= (const modnum& o) {
  v -= o.v;
  if (v < 0) v += MOD;
  return *this;
 }
 modnum& operator *= (const modnum& o) {
  v = int(ll(v) * ll(o.v) % MOD);
  return *this;
 }
 modnum& operator /= (const modnum& o) {
  return *this *= (~o);
 }

 friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
 friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
 friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
 friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<int(1e9) + 7>;

void load() {

}

const int N = 100100;

char s[N];

void solve() {
 scanf("%s", s);
 int n = strlen(s);
 num sol = 1;
 num sols[N];
 sols[1] = 1;
 sols[2] = 2;
 for (int k = 3; k < N; k++) {
  sols[k] = sols[k-1] + sols[k-2];
 }
 auto calc = [&](int k) -> num {
  return sols[k];
 };
 int ind = 0;
 while (ind < n) {
  if (s[ind] == 'm' || s[ind] == 'w') {
   printf("0\n");
   return;
  }
  if (s[ind] != 'n' && s[ind] != 'u') {
   ind++;
   continue;
  }
  int ind_ = ind;
  while (ind_ < n && s[ind_] == s[ind]) ind_++;
  sol *= calc(ind_ - ind);
  ind = ind_;
 }
 printf("%d\n", (int) sol);
}

int main() {
 load();
 solve();
 return 0;
}
