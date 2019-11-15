#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin); //freopen("output.txt", "w", stdout);
	int t , n; string s1, s2;
	cin >> t;
	while(t-- && cin >> n >> s1 >> s2){
		int diff1 = -1, diff2 = -1; 
		for(int i = 0; i < n; i++){
			if(s1[i] != s2[i]){
				if(diff1 == -1)
					diff1 = i;
				else{
					diff2 = i;
				}
			}
		}
		if(diff2 != -1)
			swap(s1[diff1], s2[diff2]);
		
		cout << (s1 == s2 ? "YES" : "NO" ) << endl;
		
	}
	return 0;
}
