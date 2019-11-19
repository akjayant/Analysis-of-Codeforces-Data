#include <bits/stdc++.h>
#define stop system("pause")
#define INP freopen("input.txt","r",stdin)
#define OUTP freopen("output.txt","w",stdout)
#define int long long
using namespace std;

typedef long long ll;



main()
{
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v;
    for(int i(0); i < n;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int x,y; x = y = 0;
    int l,r; l = 0;
    r = v.size()-1;
    int now = 0 ;
    while(l <= r){
        if(now%2 == 0){
            x+=v[l];
            l++;
        }
        else {
            y+=v[r];
            r--;
        }
        now++;
    }
    //cout << x << ' ' << y << endl;
    cout << x*x+y*y;
    return 0;
}
/*
*/
