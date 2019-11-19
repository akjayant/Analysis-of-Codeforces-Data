#include "bits/stdc++.h"
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 100000000007;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

// Print fn to print array

int main(){
	int t;
	cin >> t;
	while(t--){
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;

    	int res=n;
    	for(int i=0;i<n;i++){
    		if(s[i]=='1'){
    			res = max(res,2*(i+1));
    			res = max(res,2*(n-i));
    		}
    	}
    	cout << res << endl;
	}	
	return 0;
}
