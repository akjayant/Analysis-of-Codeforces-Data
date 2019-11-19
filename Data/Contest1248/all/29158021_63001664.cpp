// Need to git gud and reach 1900+
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pi pair < int, int >
#define prev prev123
#define next next123
#define pow pow123
#define left left123
#define right right123

const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

ll t[4 * N];
ll a[N], ans[N], mx[4 * N], debt[4 * N];
int n, p;

void push (int v, int l, int r){
    if (l != r){
        mx[v + v] = max(mx[v + v], mx[v]);
        mx[v + v + 1] = max(mx[v + v + 1], mx[v]);
    }
    t[v] = max(mx[v], t[v]);
    mx[v] = 0;
}

void build (int v, int l, int r){
    if (l == r)
        t[v] = a[l];
    else {
        int mid = (l + r) >> 1;
        build(v + v, l, mid);
        build(v + v + 1, mid + 1, r);
        t[v] = min(t[v + v], t[v + v + 1]);
    }
}

void upd (int v, int l, int r, int ql, int qr, ll val){
    push(v, l, r);
    if (r < ql || qr < l)
        return;
    if (ql <= l && r <= qr){
        mx[v] = max(mx[v], val);
        push(v, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(v + v, l, mid, ql, qr, val);
    upd(v + v + 1, mid + 1, r, ql, qr, val);
    t[v] = min(t[v + v], t[v + v + 1]);
}

int get (int v, int l, int r){
    push(v, l, r);
    if (l == r){
        t[v] = LINF;
        return l;
    }
    int mid = (l + r) >> 1;
    push(v + v, l, mid);
    push(v + v + 1, mid + 1, r);
    int temp = 0;
    if (t[v + v] <= t[v + v + 1])
        temp = get(v + v, l, mid);
    else
        temp = get(v + v + 1, mid + 1, r);
    t[v] = min(t[v + v], t[v + v + 1]);
    return temp;
}

main(){ // If you don't know what to do, check the text box at the bottom
    cin >> n >> p;
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    stack < ll > st;
    int it = 1;
    while (it <= n){
        ll mn = t[1];
        int pos = get(1, 1, n);
        while (!st.empty() && st.top() <= mn)
            st.pop();
        if (!st.empty())
            ans[pos] = st.top() + p;
        else
            ans[pos] = mn + p;
        st.push(ans[pos]);
        upd(1, 1, n, pos, n, ans[pos]);
        it++;
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
}

/*
    Totally not inspired by BenQ's template
    Things you should do:
    1. Look for stupid typos in code e.g 1 instead of -1 etc
    2. Check if there is no infinite loops
    3. "Measure twice, cut once"
    4. Stay focused
*/

