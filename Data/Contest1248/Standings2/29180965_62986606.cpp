#include <stdio.h>
#include <vector>
#include <algorithm>
#define i(a) scanf("%lld",&a)
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

vector<long long> v;
int main() {
	long long t;
	i(t);
	long long sum = 0;
	rep(i,0,t) {
		long long x;
		i(x);
		sum += x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	long long b=0;
	rep (i, 0, t / 2) {
		b += v[i];
	}
	printf("%lld", b* b + (sum - b) * (sum - b));
}