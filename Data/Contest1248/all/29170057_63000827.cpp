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
int n,m;
ll res;
ll md=1e9+7;
ll d[100010];
void build()
{
	d[0]=1;
	d[1]=1;
	for (int i=2;i<=100000;i++) d[i]=(d[i-1]+d[i-2])%md;
}
int main()
{
	build();
	cin >>n>>m;
	cout <<(((d[n]+d[m]-1)%md)*2)%md;
	return 0;
}
