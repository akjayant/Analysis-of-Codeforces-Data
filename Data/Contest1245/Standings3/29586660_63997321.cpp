#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 1e5+10;
int a[N];
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int gc = __gcd(a,b);
        if(gc==1)   puts("Finite");
        else puts("Infinite");
    }






    return 0;
}