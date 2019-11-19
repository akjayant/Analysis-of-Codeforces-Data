#include<bits/stdc++.h>

/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
*/
using namespace std;

#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()

const LL MOD = (1e9) + 7 ;
const LD EPS = 0.0000001 ;

LL pows(LL a, LL b)
{
	if (b == 0) return 1LL;
	LL temp = pows(a, b / 2);
	temp = (temp * temp) % MOD;
	if (b % 2) temp = (temp * a) % MOD;
	return temp;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--){
    	LD a, b, c, d, k; cin >> a >> b >> c >> d >>k;
    	int pen = ceil(a / c);
    	int pencil = ceil(b / d);
    	if (pen + pencil > k) cout << "-1\n";
    	else cout << pen << " " << pencil << endl;
    }

	return 0;
}