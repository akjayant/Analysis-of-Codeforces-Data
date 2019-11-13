//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

int main()
{
    int k;
    scanf("%d",&k);
    while(k--){
        int n;
        scanf("%d",&n);
        string s,t;
        cin >> s >> t;
        vector<pair<char,char> >v;
        for(int i = 0;i < n;i++){
            if(s[i] != t[i]) v.push_back({s[i],t[i]});
        }
        if(v.size() == 2){
            if(v[0].ff == v[1].ff && v[0].ss == v[1].ss) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}
