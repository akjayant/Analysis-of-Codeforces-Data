#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>  
#include <numeric>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forx(i,x,n) for (int i = x; i < int(n); i++)
#define form(i, n) for (int i = n-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(a) int(a.size())
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define summ(b,k) int(accumulate(b.begin(), b.begin() + k, 0))
#define ll long long
#define srt(a) sort(a.begin(), a.end());
#define fi first
#define se second
using namespace std;
const ll inf = 1e9 + 7;

int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ll n, i, j,m,k,q,a,b,c,r;
	cin >> n; if (n % 2 == 1) k = (n / 2) + 1; else k = n / 2;
		forn(j, n) {
			forn(i, k) { cout << n * i + j + 1 << " "; }
			forn(i, (n / 2)) { cout << n * n - j - i * n << " "; }
			cout << endl;
		}



}