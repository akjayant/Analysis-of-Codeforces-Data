#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define PI acos(-1.0)
const int N=1e3 + 5;
const int M=1e5 + 5;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin>>tt;
    while(tt--){
        int n,i;
        cin>>n;
        char s[N];
        cin>>s;
        int ans = n;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                ans = max(ans,2*(max(i+1,n-i)));
            }
        }
        cout << ans << endl;
    } 


 
    return 0;
}