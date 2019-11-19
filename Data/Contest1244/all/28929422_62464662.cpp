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

class CF12440 {
public:
  void solve(customIO &io) {
    int t = io.nextInt();
    while (t--) {
      int a = io.nextInt();
      int b = io.nextInt();
      int c = io.nextInt();
      int d = io.nextInt();
      int k = io.nextInt();
      int p = a / c;
      if (a % c != 0)
        ++p;
      int q = b / d;
      if (b % d != 0)
        ++q;
      if (p + q <= k) {
        io.println(p, " ", q);
      } else
        io.println(-1);
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
  CF12440 solver;
  solver.solve(io);
  return 0;
}
