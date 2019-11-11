#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<stack>
#include<algorithm>
#include<string>
#include<string.h>
#include<assert.h>
#include<iomanip>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll fpb(ll a, ll b){
    if(b == 0)return a;
    return fpb(b, a % b);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        if(fpb(a, b) == 1)cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }   
}