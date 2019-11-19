#include <iostream>
#include <string>
using namespace std;

int t;
int n;
string s;

int ans(){
	int firstOcc = -1;
	int lastOcc = -1;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0') continue;
		if(firstOcc == -1) firstOcc = i;
		lastOcc = i;
	}
	if(firstOcc == -1) return n;
	int ans = n + 1;
	//case left
	ans = max(ans, (lastOcc + 1) * 2);
	//case right
	ans = max(ans, (int)(s.length() - firstOcc) * 2);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> s;
		cout << ans() << "\n";
	}
}