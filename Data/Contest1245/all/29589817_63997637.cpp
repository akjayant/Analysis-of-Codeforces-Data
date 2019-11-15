#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b, a %b);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin >>t;
    while(t--){
        int a, b;cin >> a >> b;
        if(gcd(a, b) == 1){
            cout << "Finite" <<endl;
        }else cout << "Infinite" <<endl;

    }
}


