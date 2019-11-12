#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e4+5;

char s[sz], t[sz];

int main()
{
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        scanf("%s %s", s, t);

        int d[30]={0};
        for(int i=0; s[i]; i++) d[s[i]-'a']++;
        for(int i=0; t[i]; i++) d[t[i]-'a']++;

        bool yes=1;
        for(int i=0; i<30; i++) if(d[i]&1) yes=0;

        if(!yes) puts("No");
        else {
            puts("YES");
            vector < pair <int,int> > ans;
            for(int i=0; i<n; i++) {
                if(s[i]==t[i]) continue;
                for(int j=i+1; j<n; j++) {
                    if(s[j]==s[i]) {
                        swap(s[j],t[i]);
                        ans.push_back({j,i});
                        break;
                    }
                    if(t[j]==s[i]) {
                        swap(s[j],t[j]);
                        ans.push_back({j,j});
                        swap(s[j],t[i]);
                        ans.push_back({j,i});
                        break;
                    }
                }
            }

            printf("%d\n", ans.size());
            for(int i=0; i<ans.size(); i++) {
                printf("%d %d\n", ans[i].first+1, ans[i].second+1);
            }
        }
    }
}
