#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int cases;
	cin >> cases;

	while(cases--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);
		int i = n-1;
		int width = 0;
		while(i != -1) {
			if(arr[i] > width) {
				width++;
				i--;
			} else {
				break;
			}
		}

		cout << width << endl;
	}
}