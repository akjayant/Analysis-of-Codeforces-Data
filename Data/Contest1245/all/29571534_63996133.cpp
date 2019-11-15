#include <cstdio>
using namespace std;

inline void read (int& s) {
	s = 0; int f = 0;
	static char c = getchar ();
	while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar ();}
	while (c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar ();
	s = f ? -s : s; return ;
}

int gcd (const int p, const int q) {return q ? gcd (q, p % q) : p;}

int t, a, b;

int main () {
	read (t);
	while (t--) {
		read (a), read (b);
		if (gcd (a, b) == 1) puts ("Finite");
		else puts ("Infinite");
	}
	return 0;
}

