#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

const long long MOD = 1000000000 + 7;

long long fib[100010];

void init()
{
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;
	for (int i = 3 ; i < 100010 ; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
}

long long rfib[100010];
void init2()
{
	rfib[0] = 0;
	rfib[1] = 1;
	rfib[2] = 1;
	rfib[3] = 2;
	for (int i = 4 ; i < 100010 ; i++)
	{
		rfib[i] = (rfib[i - 1] + rfib[i - 2] + 1) % MOD;
	}
}


long long r, c;

int main()
{
	init();
	init2();
	
	scanf("%I64d%I64d", &r, &c);
	
	if (r == 1 && c == 1)
	{
		printf("2\n");
		return 0;
	}
	
	if (r > c)
	{
		long long tmp = r;
		r = c;
		c = tmp;
	}
	
	long long totalC;
	totalC = (rfib[c]) % MOD;
	long long totalR = (fib[r + 1]) % MOD;
	
	long long total = (totalC + totalR) % MOD;
	total = total * 2 % MOD;
	printf("%I64d\n", total);
	
	
	return 0;
}

//纵横两方向的Fib
//拆解成 