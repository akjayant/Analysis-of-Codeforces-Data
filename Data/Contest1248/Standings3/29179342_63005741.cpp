#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int maxx;
string s;
int x[1000005];
int solve(){
    int i, sum = 0, ans=0;
    for (i=0; i<s.size(); i++){
        if (s[i] == '(')
                sum ++;
        else sum --;
        if (sum == 0)
            ans ++;
        if (sum < 0)
            ans = 0, sum = 0;

    }
    if (sum > 0)
        ans ++;
    return ans;
}
int main (){

	int i, j, a=0, b=0, ans, n, x, y;
	cin >>n >>  s;
	for (i=0; i<s.size(); i++){
        if (s[i] == '(') a++;
        else b++;
	}
	if (a != b){
        cout << 0 << "\n" << "1 1" ;
        return 0;
	}
	maxx = solve(); x=y=0;
	for (i=0; i<s.size(); i++){
        for (j=i; j<s.size(); j++){
            if (s[i] != s[j]){
                swap (s[i], s[j]);
                ans = solve();
                if (maxx < ans){
                     maxx = ans;
                     x = i, y = j;
                }

                swap (s[i], s[j]);

            }
        }
	}
	cout << maxx << "\n" << x+1 << " " << y+1;
	return 0;
}
