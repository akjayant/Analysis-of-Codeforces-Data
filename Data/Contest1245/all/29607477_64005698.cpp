#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
#define pi 3.14159265358979323846
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
 
const int o = 1 << 17;
 
const int mod = 1000000007;
 
const int inf = 0x3f3f3f3f;
const ll huge = 100000000000000000LL;
 
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<pli, int> st;
typedef priority_queue<st> pq;
 
int main() {
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int a, b, c;
		string bob;
		cin >> n;
		cin >> a >> b >> c;	
		cin >> bob;	
		string alice = "";
		for (int j = 0; j < n; j++)
			alice += '.';
		int wins = 0;
			for (int k = 0; k < n; k++)
				if (bob[k] == 'S' && a > 0) {
					alice[k] = 'R';
					wins++;
					a--;				
				}
			for (int k = 0; k < n; k++)
				if (bob[k] == 'R' && b > 0) {
					alice[k] = 'P';
					wins++;
					b--;				
				}
		
			for (int k = 0; k < n; k++)
				if (bob[k] == 'P' && c > 0) {
					alice[k] = 'S';
					wins++;
					c--;				
				}
			
		if (wins < (n + 1) / 2) 
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for (int j = 0; j < n; j++) {
				if (alice[j] != '.')
					cout << alice[j];
				else
					if (a > 0) {
						cout << 'R';	
						a--;								
					}		
				else
					if (b > 0) {
						cout << 'P';
						b--;					
					}	
				else {
					cout << 'S';
					c--;				
				}
			}		
			cout << endl;
		}
	}
    return 0;
}
