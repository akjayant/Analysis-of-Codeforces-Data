#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	int n;
	string a;
	string b;

	while (cases--) {
		cin >> n;
		cin >> a >> b;
		int i = 0;
		while (i != n) {
			if (a[i] == b[i]) {
				i++;
				continue;
			} else {
				int index = i;
				i++;
				while (i != n && b[i] == a[i]) {
					i++;
				}

				if (i != n) {
					char temp = a[index];
					a[index] = b[i];
					b[i] = temp;
				}

				break;
			}
		}

		int k = 0;
		while (k != n) {
			if (a[k] != b[k]) {
				break;
			}

			k++;
		}

		if (k != n) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
}