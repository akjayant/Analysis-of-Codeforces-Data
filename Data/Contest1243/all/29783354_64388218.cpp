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
    ll x1 = -1 , x2 = -1;
    for ( int i = 0 ; i < n ; i++ )
    {
        char x = s[i], y = t[i];
        if (s[i]==t[i]) continue;
if (x1 == -1) x1 = i;
else if (x2 == -1) x2 = i;
else {f = 1 ; break;}
    }

    if (f==1 || (x2==-1 && x1 != -1)) {cout << "No" << endl;continue;}
 else if (s[x1]==s[x2] && t[x1]==t[x2])
        cout << "Yes" << endl ;
            else cout << "No" << endl;



}









    return 0;
    }
