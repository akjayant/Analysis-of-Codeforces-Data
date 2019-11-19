#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define INF 1000000000000000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b, c, d, k;

    cin >> t;

    while(t--){
    	cin >> a >> b >> c >> d >> k;

    	int num1 = (a/c);

    	if((a%c))
    		num1++;

    	int num2 = (b/d);

    	if((b%d))
    		num2++;

    	if(((num1 + num2) <= k)){
    		cout << num1 << " " << num2 << endl;
    	}

    	else{
    		cout << -1 << endl;
    	}
    }

    return 0;
}