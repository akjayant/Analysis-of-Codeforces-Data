#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define int long long

using namespace std;

const int N = 100707;
int n, k;
int a[N];
set <int> st;
map <int,int> mp;
signed main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("diameter.in", "r", stdin);
    //freopen("diameter.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        st.insert(a[i]);
        mp[a[i]]++;
    }

    int l = *st.begin();
    int r = *st.rbegin();
    int coll = mp[l];
    int colr = mp[r];
    if (r == l){
        cout << 0 << endl;
        return 0;
    }
    st.erase(l), st.erase(r);

    while (r > l){
        if (st.size() == 0){
            if (coll <= colr){
                l = l + k / coll;
                if (l >= r){
                    cout << 0 << endl;
                    return 0;
                }
                else {
                    cout << r - l << endl;
                    return 0;
                }
            }
            else {
                r = r - k / colr;
                if (l >= r){
                    cout << 0 << endl;
                    return 0;
                }
                else {
                    cout << r - l << endl;
                    return 0;
                }
            }
        }
        if (coll <= colr){
            int nxt = *st.begin();
            int need = nxt;
            if ((nxt - l) * coll <= k){
                k = k - (nxt - l) * coll;
                l = nxt;
                coll = coll + mp[nxt];
                st.erase(nxt);
            }
            else {
                l = l + k / coll;
                cout << r - l << endl;
                return 0;
            }
        }
        else {
            int nxt = *st.rbegin();
            int need = nxt;
            if ((r - nxt) * colr <= k){
                k = k - (r - nxt) * colr;
                r = nxt;
                colr = colr + mp[nxt];
                st.erase(nxt);
            }
            else {
                r = r - k / colr;
                cout << r - l << endl;
                return 0;
            }
        }
    }

    if (r == l){
        cout << 0 << endl;
        return 0;
    }

    return 0;
}
