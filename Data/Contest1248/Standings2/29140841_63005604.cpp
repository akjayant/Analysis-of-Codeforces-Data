#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
#define MAX(x, y) ((x) > (y) ? (x):(y)) 
#define MIN(x, y) ((x) > (y) ? (y):(x))
#define ABS(x) ((x) > 0 ? ((x) : -(x)))
using namespace std;
const int MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
char str[510];

int check() {
	stack<int> st1, st2;
	int s = 0;
	int e = N - 1;
	while (1) {
		while (s <= e) {
			if (str[s] == '(') st1.push(0);
			else if (str[s] == ')' && !st1.empty()) st1.pop();
			else break;
			++s;
		}
		while (s < e) {
			if (str[e] == ')') st2.push(0);
			else if (str[e] == '(' && !st2.empty()) st2.pop();
			else {
				--e;
				st1.push(0);
				break;
			}
			--e;
		}
		if (s >= e) break;
	}
	int cnt = 0;
	if (st1.empty() && st2.empty()) {
		for (int i = 0; i < N; ++i) {
			if (str[(e + 1 + i) % N] == '(') st1.push(0);
			else {
				st1.pop();
				if (st1.empty()) ++cnt;
			}
		}
	}
	return cnt;
}

int main()
{
	int i, j;
	scanf("%d%s", &N, str);
	int a, b, maxi;
	maxi = a = b = 0;
	for (i = 0; i < N; ++i) {
		for (j = i; j < N; ++j) {
			swap(str[i], str[j]);
			int temp = check();
			if (temp > maxi) {
				maxi = temp;
				a = i;
				b = j;
			}
			swap(str[i], str[j]);
		}
	}
	printf("%d\n%d %d",maxi, a + 1, b + 1);
}

