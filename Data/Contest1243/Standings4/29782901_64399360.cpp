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

		int arr[26] = {0};

		for (int i = 0; i < n; i++) {
			arr[a[i] - 'a']++;
			arr[b[i] - 'a']++;
		}

		int z = 0;
		for (; z < 26; z++) {
			if (arr[z] % 2 == 0) {
				continue;
			} else {
				break;
			}
		}

		if (z != 26) {
			cout << "No" << endl;
			continue;
		}

		int swaps = 0;
		int matrix[200][2];

		int i = 0;
		while (i != n) {
			if (a[i] == b[i]) {
				i++;
				continue;
			} else {
				int k = i + 1;
				char x = a[i];
				while (k != n && a[k] != x) {
					k++;
				}

				if (k != n) {
					char temp = b[i];
					b[i] = a[k];
					a[k] = temp;
					matrix[swaps][0] = k;
					matrix[swaps][1] = i;
					swaps++;
				} else {
					int l = i + 1;
					while (l != n && b[l] != x) {
						l++;
					}

					if (l != n) {
						char temp = a[l];
						a[l] = b[l];
						b[l] = temp;
						matrix[swaps][0] = l;
						matrix[swaps][1] = l;
						swaps++;

						temp = a[l];
						a[l] = b[i];
						b[i] = temp;
						matrix[swaps][0] = l;
						matrix[swaps][1] = i;
						swaps++;
					}
				}
			}
		}

		cout << "Yes" << endl;
		cout << swaps << endl;
		for(int i = 0; i < swaps; i++) {
			cout << matrix[i][0] + 1 << " " << matrix[i][1] + 1 << endl;
		}

	}
}