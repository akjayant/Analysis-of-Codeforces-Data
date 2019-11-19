#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <functional>
#include <utility>
#include <stdio.h>
#define ll long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
int n;
ll a[100010];
ll x,y;
int main()
{
	cin >>n;
	for (int i=0;i<n;i++) cin >>a[i];
	sort(a,a+n);
	for (int i=0;i<n/2;i++) x+=a[i];
	for (int i=n/2;i<n;i++) y+=a[i];
	cout <<x*x+y*y;
	return 0;
}
