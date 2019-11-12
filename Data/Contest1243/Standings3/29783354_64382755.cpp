 #include<bits/stdc++.h>
    #include <fstream>
    #define ll long long
#define f first
#define s second
    using namespace std;



    int main(){

ll k ;
cin >> k;
for ( int o = 1 ; o <= k ; o++ )
{
    ll n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vector < pair < ll , ll > > ans;
    ll f = 0;
    for ( int i = 0 ; i < n ; i++ )
    {
        char x = s[i], y = t[i];
        if (x == y) continue;
ll        x1=0,y1=0,x2=0,y2=0;
        for ( int j = i+1 ; j < n ; j++ )
        {
            if (s[j]==x) x1 = j;
            if (t[j]==x) x2 = j;
            if (s[j]==y) y1 = j;
            if (t[j]==y) y2 = j;
        }
        if (x1==0 && x2==0 && y1==0 && y2==0) {f = 1;cout << "No" << endl;break;}
      if (x1!=0) {ans.push_back({x1,i});swap(s[x1],t[i]);continue;}
      if (y2!=0) {ans.push_back({i,y2});swap(s[i],t[y2]);continue;}
      if (x2!=0) {ans.push_back({i+1,x2});ans.push_back({i+1,i});swap(s[i+1],t[x2]);swap(s[i+1],t[i]);continue;}
      if (y1!=0) {ans.push_back({y1,i+1});ans.push_back({i,i+1});swap(s[y1],t[i+1]);swap(s[i],t[i+1]);continue;}
    }
    if (f==0 && s[n-1]!=t[n-1]) {cout << "No" << endl;continue;}
    if (f==0)
    {
        cout << "Yes" << endl << ans.size() << endl;
        for ( int i = 0 ; i < ans.size() ; i++ )
        {
            cout << ans[i].f+1 << " " << ans[i].s+1 << endl;
        }
        cout << endl;
    }


}









    return 0;
    }
