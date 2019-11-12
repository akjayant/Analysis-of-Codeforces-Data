#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

const int MAXN = 1000;

int n, a[MAXN + 5];

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int temp;
cin >> temp;
while(temp--){
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	sort(a, a + n);
	int sol = 0;
	for(int i = n - 1 ; i >= 0 ; --i){
		sol = max(sol, min(n - i, a[i]));
	}
	cout << sol << endl;
}

return 0;
}

