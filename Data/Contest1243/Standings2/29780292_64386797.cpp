#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define int long long

bool prime(int n) {
    bool d = 1;
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n  % i == 0) {
            d = 0;
            break;
        }
    }
    if(d) {
        return true;
    } else {
        return false;
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<int> ans;
    while (n != 1) {
	    for (int i = 2; i <= sqrt(n); i++) {
	        if (n % i == 0 && prime(i)) {
	            ans.push_back(i);
	            n /= i;
	            break;
	        }
	        if (n % i == 0 && prime(n / i)) {
	            ans.push_back(n / i);
	            n = i;
	            break;
	        }
	    }
        if (prime(n)) {
            ans.push_back(n);
            n = 1;
        }
    }
    for (int i = 0; i < (int)ans.size() - 1; i++) {
    	if (ans[i] != ans[i + 1]) {
    		cout << 1;
    		return 0;
    	}
    }

    cout << ans[0];
    return 0;
}