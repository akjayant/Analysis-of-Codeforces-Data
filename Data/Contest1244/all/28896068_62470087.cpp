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

int t, n;
char s[N];

int main()
{
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		for(int i = 1; i <= n; i++) cin >> s[i];
		
		int ans = n;
		
		for(int i = 1; i <= n; i++) {
			if(s[i] == '0') continue;
			
			ans = max(2 * (n - (i-1)), ans);
			
			break;
		}
		for(int i = n; i >= 1; i--) {
			if(s[i] == '0') continue;
			
			ans = max(2 * (n - (n-i)), ans);
			
			break;
		}
		cout << ans << "\n";
	}
}