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

int main() {
  int t = readint();
  forl(t) {
    int n = readint();
    vi a(n);
    lli odd1 = 0ll;
    lli even1 = 0ll;
    fori(n) {
      a[i] = readint();
      if (a[i] & 1) odd1++; else even1++;
    }
    int m = readint();
    vi b(m);
    lli odd2 = 0ll;
    lli even2 = 0ll;
    fori(m) {
      b[i] = readint();
      if (b[i] & 1) odd2++; else even2++;
    }
    cout << odd1 * odd2 + even1 * even2 << endl;
  }

  return 0;
}
