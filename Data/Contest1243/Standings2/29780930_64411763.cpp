#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=987654321987654321;
const int inf=987654321;
int n, m;
unordered_set<int> us[100010];
vector<int> link[100010];
set<int> s, ss, ans;
int num;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        us[a].insert(b);
        us[b].insert(a);
        link[a].pb(b);
        link[b].pb(a);
    }
    ans.insert(1);
    for(int i=2; i<=n; i++){
        s.insert(i);
    }
    for(int k=1; k<=n; k++){
        if(ans.size()==0){
            num++;
            ans.insert(*s.begin());
            s.erase(s.begin());
        }
        int i=*ans.begin();
        ss.clear();
        for(auto j=s.begin(); j!=s.end(); j++){
            if(!us[i].count(*j)){
                ss.insert(*j);
            }
        }
        for(auto j=ss.begin(); j!=ss.end(); j++){
            s.erase(*j);
            ans.insert(*j);
        }
        ans.erase(i);
    }
    printf("%d", num);
}
