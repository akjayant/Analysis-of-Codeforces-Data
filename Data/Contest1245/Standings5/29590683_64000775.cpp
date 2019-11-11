#include<bits/stdc++.h>
#define pb(x)push_back(x)
#define all(x) x.begin(), x.end()
#define cout2(x, y) cout << x << " " << y << endl
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl
#define N 100005

using namespace std;

int a[N];

int main(){	
	ios::sync_with_stdio(false);
	int n, a, b, GCD;
	cin >> n;
	
	for(int i = 0; i < n; i++){
	
		cin >> a >> b;
		GCD = __gcd(a, b);
			if(GCD == 1)cout << "Finite" << endl;
	else cout << "Infinite" << endl;
	}
	

}
