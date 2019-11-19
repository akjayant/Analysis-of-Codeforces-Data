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

    LL n,k; cin >> n >> k;

    map<LL,LL> M;
    for (int i = 0; i < n; i++){
    	LL x; cin >> x;
    	M[x]++;
    }

    vector<LL> arr;
    for (auto it : M) arr.PB(it.first);
   	int curX = 0;
    int curY = arr.size() - 1;
    LL mn = arr[0];
    LL mx = arr.back();
   // cout << mn << " " << mx << endl;
    while ((curX < curY) && (k > 0) && (mn < mx)){
    	if (M[mn] < M[mx]){
    		LL need = (arr[curX + 1] - mn) * M[mn];
    		if (need <= k){
    			M[arr[curX + 1]] += M[mn];
    			mn = arr[curX + 1];
    			curX++;
    			k -= need;
    		} else {
    			LL up = k / M[mn];
    			mn += up;
    			k = 0;
    		}
    	//	cout << mn << " " << mx <<  " " << k << endl;
    	} else{ 
    		LL need = (mx - arr[curY - 1]) * M[mx];
    	//	cout << need << " " << k << endl;
    		if (need <= k){
    			M[arr[curY - 1]] += M[mx];
    			mx = arr[curY - 1];
    			curY--;
    			k -= need;
    		} else {
    			LL down = k / M[mx];
    			mx -= down;
    			k = 0;
    		}
    	//	cout << mn << " " << mx << " " << k << endl;
    	}
    }

    cout << mx - mn << endl;

	return 0;
}