#include<bits/stdc++.h>
using namespace std;

#define N 200123
#define mod 1000000007

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    if(fopen("input.in", "r")){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int n;
    long long a[N], l = 0, r = 0;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
    	cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 0 ; i < n ; i++){
    	if(i < n/2) l += a[i];
    	else r += a[i];
    }
    cout << (r*r) + (l*l) << endl;
    return 0;
}