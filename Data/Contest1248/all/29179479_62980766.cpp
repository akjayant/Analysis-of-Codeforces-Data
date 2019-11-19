#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

const int MAXN = (int)1e5;
int n;
ll a[MAXN + 5];

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> n;
for(int i = 0 ; i < n ; ++i){
	cin >> a[i];
}
sort(a, a + n);
ll x = 0, y = 0;
for(int i = 0 ; i < (n + 1) / 2 ; ++i){
	x += a[n - i - 1];
}
for(int i = 0 ; i < n / 2 ; ++i){
	y += a[i];
}
ll sol = x * x + y * y;
cout << sol << endl;

return 0;
}

