#include <bits/stdc++.h>

using namespace std;

class customIO {
public:
  istream &in;
  ostream &out;
  customIO(istream &_in, ostream &_out) : in(_in), out(_out) {}
  string next() {
    string s;
    in >> s;
    return s;
  }
  double nextDouble() { return stod(next()); }
  int nextInt() { return stoi(next()); }
  long long nextLong() { return stoll(next()); }
  template <typename T> void print(T t) { out << t; }
  template <typename T, typename... U> void print(T t, U... u) {
    out << t;
    print(u...);
  }
  template <typename T, typename... U> void println(T t, U... u) {
    print(t, u..., "\n");
  }
  void println() { print("\n"); }
};

class CF1244B {
public:
  void solve(customIO &io) {
    int t = io.nextInt();
    while (t--) {
      int n = io.nextInt();
      string s = io.next();
      int res = n;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
          int left = 2 * (i + 1);
          int right = 2 * (n - i);
          res = max(res, max(left, right));
        }
      }
      io.println(res);
    }
    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(20);
  istream &in(std::cin);
  ostream &out(std::cout);
  customIO io(in, out);
  CF1244B solver;
  solver.solve(io);
  return 0;
}
