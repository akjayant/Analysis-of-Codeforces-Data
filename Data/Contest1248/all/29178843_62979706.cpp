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
	FIO
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		vector <ll> A(2);
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			A[x % 2]++;
		}
		int m;
		cin >> m;
		vector <ll> B(2);
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			B[x % 2]++;
		}
		cout << A[0] * B[0] + A[1] * B[1] << "\n";
	}
			 
}
