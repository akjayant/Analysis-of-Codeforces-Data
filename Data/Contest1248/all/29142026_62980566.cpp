#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <string>
#include <ctime>
#define ll long long
#define pint pair<int,int>
#define pii pair<int,int>
#define pci pair<char,int>
#define pdd pair<double,double>
#define pli pair<int,int>
#define pil pair<int,int>
#define pdi pair<double,int>
#define pdd pair<double,double>
#define mod 1000000007
#define mod1 1000000009
#define mod2 1000000021
#define INF 1987654321
#define MAX 2000001
long double PI = 3.141592653589793238462643383279502884197;
using namespace std;

/* 🐣🐥 */
ll arr[100001];
int main() {
	int n;
	ll ans = 0, x=0,y=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n / 2; i++) x += arr[i];
	for (int i = n / 2; i < n; i++) y += arr[i];
	printf("%lld", x*x + y * y);

	return 0;
}