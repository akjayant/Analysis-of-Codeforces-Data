#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define MOD 1000000007 
#define INF 1000000000000000000
#define uid uniform_int_distribution <int>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(all(A));
	reverse(all(A));
	ll x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		if(i < (n + 1) / 2)
		{
			x += A[i];
		}
		else
		{
			y += A[i];
		}
	}
	cout << x * x + y * y; 
}
