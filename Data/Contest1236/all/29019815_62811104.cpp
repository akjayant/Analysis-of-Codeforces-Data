#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i=0; i<int(n); i++)
#define RNG(i, f, t) for(int i=int(f); i<=int(t); i++)
#define REV(i, f, t) for(int i=int(f); i>=int(t); --i)
#define ALL(v) (v).begin(), (v).end()
bool RELAXED = false;
template<int,typename T> struct MINMAX{ T val; MINMAX(T val) : val(val) {} };
template<typename T> MINMAX<1,T> MAX(T val) { return MINMAX<1,T>(val); };
template<typename T> MINMAX<2,T> MIN(T val) { return MINMAX<2,T>(val); };
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<1,U> rhs) { return lhs = (rhs.val > lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<2,U> rhs) { return lhs = (rhs.val < lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T> inline vector<T> readVector(int n) { vector<T> vec(n); FOR(i,n) cin>>vec[i]; return vec; }
template<typename T> void EXIT(T answer) { cout<<answer<<endl; exit(0); }
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef signed long long int ll;

const int MAXN=1e5+5;
set<int> row[MAXN];
set<int> col[MAXN];

int h,w,k;
ll steps=0;

void solve() {
    int pr=1;
    int pc=1;
    int d=0;

    int minr=1, maxr=h+1;
    int minc=0, maxc=w+1;
    int oldpr=0;
    int oldpc=1;
    while(true) {

//        if(pc>maxc) return;
//        if(pc<minc) return;
//        if(pr>maxr) return;
//        if(pr<minr) return;


        if(d==0) {
            pc = *row[pr].upper_bound(pc)-1;
            pc |= MIN(maxc-1);
            maxc = pc;
        }
        if(d==2) {
            pc = *prev(row[pr].upper_bound(pc))+1;
            pc |= MAX(minc+1);
            minc=pc;
        }
        if(d==1) {
            pr = *col[pc].upper_bound(pr)-1;
            pr |= MIN(maxr-1);
            maxr=pr;
        }
        if(d==3) {
            pr = *prev(col[pc].upper_bound(pr))+1;
            pr |= MAX(minr+1);
            minr=pr;
        }

        if(pr==oldpr && pc==oldpc)
            return;

        d=(d+1)%4;
        steps += abs(pc-oldpc) + abs(pr-oldpr);
//        cerr<<"pos "<<pr<<","<<pc<<endl;
        oldpr=pr;
        oldpc=pc;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>h>>w>>k;
//    if(k==0) EXIT("Yes");
    FOR(i,k) {
        int x,y;
        cin>>x>>y;
        row[x].insert(y);
        col[y].insert(x);
    }

    FOR(i,h+2) {
        row[i].insert(0);
        row[i].insert(w+1);
    }
    FOR(i,w+2) {
        col[i].insert(0);
        col[i].insert(h+1);
    }

    solve();
    cerr<<steps<<" "<<1LL*w*h-k<<endl;
    cout<<(steps>=1LL*w*h-k ? "Yes" : "No")<<endl;

    return 0;
}

