#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <ctime>
#include <map>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll k=0;
    for(int i=1;i<=n;i++) cin>>a[i],k+=a[i];
    sort(a+1,a+n+1);
    ll p=0;
    for(int i=1;i<=n/2;i++){
        p+=a[i];    
    }
    ll ans=(k-p)*(k-p)+p*p;
    if(n&1){
        p+=a[n/2+1];
        ans=max(ans,(k-p)*(k-p)+p*p);
    }
    cout<<ans<<endl;
	return 0;
}
