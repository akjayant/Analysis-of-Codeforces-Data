#include "bits/stdc++.h"

using namespace std;

using lli = long long int;
using vb = vector<bool>;
using vc = vector<char>;
using vd = vector<double>;
using vi = vector<int>; using vvi = vector<vi>;
using vlli = vector<lli>; using vvlli = vector<vlli>;
using pi = pair<int, int>; using plli = pair<lli, lli>;
#define pb push_back
#define mp make_pair
#define fori(x) for(int i = 0; i < x; ++i)
#define forj(x) for(int j = 0; j < x; ++j)
#define fork(x) for(lli k = 0; k < x; ++k)
#define forl(x) for(lli l = 0; l < x; ++l)

void readc(char &q) { scanf("%c", &q); } char readc() { char q; scanf("%c", &q); return q; }
void readint(int &q) { scanf("%d", &q); } int readint() { int q; scanf("%d", &q); return q; }
void readlong(lli &q) { scanf("%lld", &q); } lli readlong() { lli q; scanf("%lld", &q); return q; }
void readdbl(double &q) { scanf("%lf", &q); } double readdbl() { double q; scanf("%lf", &q); return q; }
void printint(int q) { printf("%d", q); } void printlong(lli q) { printf("%lld", q); }
void printdbl(double q, int p = 6) { printf("%.*lf", p, q); }
void readln() { scanf("\n"); } void println() { printf("\n"); } void printsp() { printf(" "); }
void print(int q) { printint(q); } void print(long q) { printlong((lli)q); } void print(lli q) { printlong(q); }
void print(double q) { printdbl(q); }void print(char c) { printf("%c", c); }
void print(pi q) { print(q.first); printsp(); print(q.second); } void print(vi q) { fori(q.size()) { print(q[i]); printsp(); } }
void print(vlli q) { fori(q.size()) { print(q[i]); printsp(); } } void print(vd q) { fori(q.size()) { print(q[i]); printsp(); } }
template <typename T> void println(T q) { print(q); println(); }

template<typename T> T maxim(T first, T second) { return (first > second) ? first : second; }
template<typename T> T maxim(T first, T second, T third) { return mndlim(maxim(first, second), third); }
template<typename T> T minim(T first, T second) { return (first < second) ? first : second; }
template<typename T> T minim(T first, T second, T third) { return minim(minim(first, second), third); }
template<typename T> T middle(T first, T second, T third) { return first + second + third - maxim(first, second, third) - minim(first, second, third); }
template<typename T> T abs(T arg) { return arg < 0 ? -arg : arg; }

const lli modulo = 1000000007;

lli phi[100010];
lli sum[100010];

int main() {
  int n = readint();
  int m = readint();
  phi[0] = 1;
  phi[1] = 1;
  sum[0] = 0;
  for (int i = 2; i <= maxim(n, m) + 2; ++i) {
    phi[i] = phi[i - 1] + phi[i - 2];
    if (phi[i] >= modulo) phi[i] -= modulo;
    sum[i - 1] = sum[i - 2] + phi[i - 2];
    if (sum[i - 1] >= modulo) sum[i - 1] -= modulo;
  }

  cout << (((phi[m] + sum[n - 1]) % modulo) * 2) % modulo << endl;
  return 0;
}
