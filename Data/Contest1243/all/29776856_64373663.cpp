/*
* @Author: SajidZakaria
* @Date:   2019-11-06 21:03:15
* @Last Modified by:   SajidZakaria
* @Last Modified time: 2019-11-06 21:07:54
*/

#include<bits/stdc++.h>
using namespace std;

int num[1005];

int main(){
	int k;
	cin >> k;

	while(k--) {
		int n;
		cin >> n;

		for(int i=1; i<=n; i++) cin >> num[i];

		for(int i=n; i>=1; i--) {
			int cnt = 0;
			for(int j=1; j<=n; j++) if(num[j] >= i) cnt++;
			if(cnt >= i) {
				cout << i << endl;
				break;
			}
		}
	}
}
