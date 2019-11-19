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
int tac;
ll a[2],b[2];
int n,m;
int main()
{
	cin >>tac;
	while (tac--)
	{
		a[0]=a[1]=b[0]=b[1]=0;
		cin >>n;
		for (int i=0;i<n;i++)
		{
			int t;
			cin >>t;
			a[t%2]++;
		}
		cin >>m;
		for (int i=0;i<m;i++)
		{
			int t;
			cin >>t;
			b[t%2]++;
		}
		cout <<b[0]*a[0]+b[1]*a[1]<<"\n"; 
	}
	return 0;
} 
