#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef pair <pii, int> ppi;

const int INF=0x3f3f3f3f;

int n;
int cnt[26];
char s1[55], s2[55];
vector <pii> v;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        v.clear();
        int rip=0;
        scanf("%d", &n);
        scanf("%s %s", s1, s2);
        for (int i=0; i<n; ++i) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']++;
        }
        for (int i=0; i<26; ++i) {
            if (cnt[i]%2) rip=1;
        }
        if (rip) {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for (int i=0; i<n; ++i) {
            if (s1[i]==s2[i]) continue;
            int ind=-1;
            for (int j=i+1; j<n; ++j) {
                if (s1[j]==s1[i]) ind=j;
            }
            if (ind!=-1) {
                v.pb(mp(ind, i));
                swap(s1[ind], s2[i]);
                continue;
            }
            for (int j=i+1; j<n; ++j) {
                if (s2[j]==s1[i]) ind=j;
            }
            v.pb(mp(n-1, ind));
            swap(s1[n-1], s2[ind]);
            v.pb(mp(n-1, i));
            swap(s1[n-1], s2[i]);
        }
        printf("%d\n", v.size());
        for (int i=0; i<v.size(); ++i) printf("%d %d\n", v[i].X+1, v[i].Y+1);
    }
    return 0;
}
