#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<int,int>
#define iii pair<int, ii>
#define se second
#define double long double
#define mod 1000000007
#define popcount __builtin_popcountll
using namespace std;
const double PI = acos(-1.0);

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int A = a/c + (a%c!=0);
        int B = b/d + (b%d!=0);
        if(A+B>k)cout<<-1<<endl;
        else cout<<A<<" "<<B<<Endl;
    }
}
