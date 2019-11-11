#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

char s[100005];
ll d[100005];

int main()
{
	scanf("%s", s + 1);
	d[0] = 1;
	int L = strlen(s + 1);
	for(int i = 1; i <= L; i++){
		if(s[i] == 'w' || s[i] == 'm') return !printf("0\n");
		if(s[i] == 'u' && s[i - 1] == 'u')
			d[i] += d[i - 2];
		else if(s[i] == 'n' && s[i - 1] == 'n')
			d[i] += d[i - 2];
		d[i] += d[i - 1];
		d[i] %= mod;
	}
	printf("%lld\n", d[L]);

	return 0;
}