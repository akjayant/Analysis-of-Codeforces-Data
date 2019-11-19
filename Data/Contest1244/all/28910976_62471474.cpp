//404 Not Found {=}7 (o)7 (x)7
#include<bits/stdc++.h>
using namespace std;
#define apppend push_back
#define endl "\n"
#define dbug(x) cout<<#x<<"="<<x<<endl

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5, inf = 1e9, mod= 1e9+7;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << setprecision(30);
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin>> n;
        string s;
        cin >> s;
        int al=-1,ar;
        for(int i =0;i<n;i++){
            if(s[i]=='1'){
                al = i+1;
                break;
            }
        }
        for(int i =n-1;i>=0;i--){
            if(s[i]=='1'){
                ar = i+1;
                break;
            }
        }
        if(al==-1)
        {
            cout << n << endl;
            continue;
        }
        int e = min(al,n-ar+1);
        cout << (2*n) - (2* (e-1)) << endl;
    }
    return 0;
}