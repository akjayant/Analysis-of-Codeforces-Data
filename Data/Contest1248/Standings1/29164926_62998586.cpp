#include <bits/stdc++.h>
#define um unordered_map
#define us unordered_set
#define f first
#define s second
#define pb push_back
#define MOD 1000000007
#define MOD2 1000000009
#define BASE 29
#define BASE2 31
#define eps 1e-9
#define INF 1000000002

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<pii,pii> piiii;
const int N = 100002;
const int BIT = 50;

int get_beauty(int n, string & s) {
    int ans = 0;
    int curr =0;
    int mini = 0;
    for(char c: s) {
        if(c == '(')
            curr++;
        else
            curr--;
        mini = min(mini, curr);
    }
    if(curr != 0)
        return 0;
    for(int i =0;i<n;i++) {
        if(!mini)
            ans++;
        if(s[i] == '(')
            mini--;
        else
            mini++;
    }
    return ans;
}

int main() {
    int n;
    string s;
    cin>>n>>s;
    int ans = get_beauty(n, s);
    pair<int,int> p = {0, 0};
    for(int i =0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(s[i] == s[j])
                continue;
            swap(s[i], s[j]);
            int currAns = get_beauty(n,s);
            if(currAns > ans)
                ans = currAns, p = {i, j};
            swap(s[i], s[j]);
        }
    }
    cout<<ans<<endl<<p.first+1<<" "<<p.second+1;
    return 0;
}
