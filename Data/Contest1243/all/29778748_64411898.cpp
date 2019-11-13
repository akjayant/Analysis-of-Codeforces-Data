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
        vector<pair<int,int> >ans;
        bool cck = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == t[i]) continue;
            bool ck = 0;
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                if(s[i] == s[j] && t[i] == t[j]){
                    swap(s[j],t[i]);
                    ans.push_back({j,i});
                    ck = 1;
                    break;
                }
                else if(s[i] == t[j] && t[i] == s[j]){
                    swap(s[j],t[j]);
                    ans.push_back({j,j});
                    swap(s[j],t[i]);
                    ans.push_back({j,i});
                    ck = 1;
                    break;
                }
            }
            if(ck) continue;
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                if(s[j] != t[j] && s[j] == s[i]){
                    swap(s[j],t[i]);
                    ans.push_back({j,i});
                    ck = 1;
                    break;
                }
                else if(s[j] != t[j] && t[j] == s[i]){
                    swap(s[j],t[j]);
                    ans.push_back({j,j});
                    swap(s[j],t[i]);
                    ans.push_back({j,i});
                    ck = 1;
                    break;
                }
            }
            if(ck == 0){
                cck = 1;
                break;
            }
        }
        if(cck) printf("No\n");
        else{
            if(s == t){
                printf("Yes\n");
                printf("%d\n",ans.size());
                for(int i = 0;i < ans.size();i++){
                    printf("%d %d\n",ans[i].ff+1,ans[i].ss+1);
                }
            }
            else printf("No\n");
        }
    }
    return 0;
}
