//Suleyman Atayew

#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define N 100010
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define inf 1000000007
#define pii pair <int, int>

using namespace std;

int t;
int a, b, c, d, k;

int main()
{
	cin >> t;
	
	while(t--) {
		cin >> a >> b >> c >> d >> k;
		
		int x = a/c + (a%c ? 1 : 0);
		int y = b/d + (b%d ? 1 : 0);
		
		if(x + y > k) cout << "-1\n";
		else cout << x << " " << y << "\n";
	}
}