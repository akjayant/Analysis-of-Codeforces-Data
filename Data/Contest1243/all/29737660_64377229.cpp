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
#define fi first
#define se second
const LL MOD = 1000000000 + 7;
const LD EPS = 0.0000001 ;
#define MPP(a, b, c) MP(MP(a, b), c)
#define PII pair<pair<LL,LL>, LL>
 
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
        int n; cin >> n;
    	string s1, s2; cin >> s1 >> s2;
    	vector<int> v;
    	for (int i = 0; i < s1.size(); i++){
    		if (s1[i] != s2[i]){
    			v.PB(i);
    		}
    	}
    	if (v.size() > 2){
    		cout << "No\n";
    		continue;
    	}
    	if (v.size() == 1){
    		cout << "No\n";
    		continue;
    	}
    	int x = v[0];
    	int y = v[1];
    	char temp = s1[x];
    	s1[x] = s2[y];
    	s2[y] = temp;
    	bool flag = true;
    	for (int i = 0; i < s1.size(); i++){
    		if (s1[i] != s2[i]){
    			flag = false;
    		}
    	}
    	if (flag) cout << "Yes\n";
    	else cout << "No\n";
    }
	return 0;
}