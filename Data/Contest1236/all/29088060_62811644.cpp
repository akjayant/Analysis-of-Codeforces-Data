#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double rl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair

#if 0
#define dbg(x) cerr << #x << ": " << (x) << endl;
#else
#define dbg(x)
#endif // 1

const int MX=100*1000+99;
int n, m, k;
int _x[MX], _y[MX];
set<int> hor[MX], vert[MX];

inline int find_bigger(const set<int>& S, int val)
{
    auto it=S.lower_bound(val);
    dbg(val);
    assert(it!=S.end());
    return *it;
}

inline int find_smaller(const set<int>& S, int val)
{
    auto it=S.lower_bound(val);
    assert(it!=S.end());
    it--;
    assert(it!=S.end());
    return *it;
}

bool solve()
{
    ll CNT_NEED=n*1LL*m-k;

    for(int i=0; i<k; i++)
    {
        int xx=_x[i], yy=_y[i];
        hor[xx].insert(yy);
        vert[yy].insert(xx);
    }

    for(int xx=1; xx<=n; xx++)
    {
        hor[xx].insert(0);
        hor[xx].insert(m+1);
    }

    for(int yy=1; yy<=m; yy++)
    {
        vert[yy].insert(0);
        vert[yy].insert(n+1);
    }

    int BND_L=0, BND_R=m+1, BND_U=0, BND_D=n+1;

    ll cnt_visited=1;
    int curr_x=1, curr_y=1, curr_dir=0, iter=0;
    while(true)
    {
        dbg(iter);
        dbg(curr_x);
        dbg(curr_y);
        dbg(curr_dir);

        int new_x, new_y;
        switch(curr_dir)
        {
        case 0:
            {
                new_y=min(find_bigger(hor[curr_x], curr_y), BND_R)-1;
                new_x=curr_x;

                BND_U=curr_x;

                break;
            }
        case 1:
            {
                dbg("HERE"); dbg(curr_x); dbg(curr_y);
                //for(auto u: vert[curr_y]) dbg(u);

                new_x=min(find_bigger(vert[curr_y], curr_x), BND_D)-1;
                new_y=curr_y;

                BND_R=curr_y;

                break;
            }
        case 2:
            {
                new_y=max(find_smaller(hor[curr_x], curr_y), BND_L)+1;
                new_x=curr_x;

                BND_D=curr_x;

                break;
            }
        case 3:
            {
                new_x=max(find_smaller(vert[curr_y], curr_x), BND_U)+1;
                new_y=curr_y;

                BND_L=curr_y;

                break;
            }
        default:
            assert(false);
            break;
        }

        cnt_visited+=abs(new_x-curr_x)+abs(new_y-curr_y);
        if(new_x == curr_x && new_y==curr_y)
        {
            if(iter==0)
            {

            }
            else
            {
                break; // couldn't go further
            }
        }

        curr_x=new_x;
        curr_y=new_y;

        iter++;
        curr_dir=(curr_dir+1)%4;
    }

    return cnt_visited==CNT_NEED;
    //assert(false);
    //return true;
}

int main()
{
    #if 0
    freopen("D.txt", "r", stdin);
    #endif
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    for(int i=0; i<k; i++)
    {
        cin >> _x[i] >> _y[i];
    }

    if(solve()) cout << "Yes";
    else cout << "No";



    return 0;
}
