#pragma region revive
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define inl inline
#define re register int
#define fa(x) t[x].fa
#define son(x, y) t[x].child[y]
#define ls(x) t[x].child[0]
#define rs(x) t[x].child[1]
#define ll long long
#define ull unsigned long long
const int inf = 0x3f3f3f3f;
#define lowbit(x) ((x) & (-x))
using namespace std;
//#ifndef _DEBUG
//#define getchar() (*(IOB.in.p++))
//#define putchar(c) (*(IOB.out.p++) = (c))
//#define io_eof() (IOB.in.p >= IOB.in.pend)
//struct IOBUF {
//	struct {
//		char buff[1 << 27], *p, *pend;
//	} in;
//	struct {
//		char buff[1 << 27], *p;
//	} out;
//	IOBUF() {
//		in.p = in.buff;
//		out.p = out.buff;
//		in.pend = in.buff + fread(in.buff, 1, 1 << 27, stdin);
//	}
//	~IOBUF() { fwrite(out.buff, 1, out.p - out.buff, stdout); }
//} IOB;
//#endif
template <typename IO>
inl void write(IO x) {
	if (x == 0) return (void)putchar('0');
	if (x < 0) putchar('-'), x = -x;
	static char buf[30];
	char *p = buf;
	while (x) {
		*(p++) = x % 10 + '0';
		x /= 10;
	}
	while (p > buf)
		putchar(*(--p));
}
inl void writestr(const char *s) {
	while (*s != 0)
		putchar(*(s++));
}
template <typename IO>
inl void writeln(IO x) {
	write(x), putchar('\n');
}
template <typename IO>
inl void writesp(IO x) {
	write(x), putchar(' ');
}
inl int readstr(char *s) {
	char *begin = s, c = getchar();
	while (c < 33 || c > 127) {
		c = getchar();
	}
	while (c >= 33 && c <= 127) {
		*(s++) = c;
		c = getchar();
	}
	*s = 0;
	return s - begin;
}
template <typename IO>
inl IO read() {
	IO x = 0;
	register bool w = 0;
	register char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') w = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return w ? -x : x;
}
template <>
inl double read<double>() {
	double x = 0;
	int w = 0, y = 0;
	ll z = 1;
	register char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') w = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9' || c == '.') {
		if (c == '.') {
			y = 1, c = getchar();
			continue;
		}
		x = x * 10 + (c ^ 48);
		if (y) z *= 10;
		c = getchar();
	}
	return (w ? -x : x) / z;
}
#pragma endregion
int n, suf[1005], pre[1005];
bool checksuf[1005], checkpre[1005];
char s[1005];
inl int check() {
	re ans = 0, sum = 0;
	for (re i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
		if (s[i] == '(')++sum;
		else sum = max(sum - 1, 0);
		checkpre[i] = !sum;
	}
	sum = 0;
	for (re i = n; i; --i) {
		suf[i] = suf[i + 1] + (s[i] == '(' ? 1 : -1);
		if (s[i] == ')')++sum;
		else sum = max(sum - 1, 0);
		checksuf[i] = !sum;
	}
	for (re i = 1; i <= n; ++i) {
		if (checkpre[i] && checksuf[i + 1] && pre[i] == -suf[i + 1])++ans;
	}
	return ans;
}
signed main() {
	n = read<int>();
	readstr(s + 1), checksuf[n + 1] = 1;
	re ans = check(), x = 1, y = 1, p;
	for (re i = 1; i <= n; ++i) {
		for (re j = i + 1; j <= n; ++j) {
			if (s[i] == s[j])continue;
			swap(s[i], s[j]), p = check();
			if (p > ans)ans = p, x = i, y = j;
			swap(s[i], s[j]);
		}
	}
	writeln(ans), writesp(x), writeln(y);
}