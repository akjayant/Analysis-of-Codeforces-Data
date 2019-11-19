#include <vector>
#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t-- > 0) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int pen = (a + c -1) / c;
		int pencil = (b + d - 1)/ d;
		// cout << "pp" << pen << " " << pencil << " " << k << " " << (pen + pencil < k) <<  "\n";
		if(pen + pencil > k) {
			cout << -1;
		} else {
			cout << pen << " " << pencil;
		}
		cout << "\n";
	}
}