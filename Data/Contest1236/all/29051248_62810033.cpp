#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define MX              200005
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vi row[100001];
vi col[100001];

int32_t main()
{
    c_p_c();
    int n,m,k; cin>>n>>m>>k;

    int cover = n*m-k;

    while(k--)
    {
        int x,y; cin>>x>>y;
        row[x].pb(y);
        col[y].pb(x);
    }

    for(int i=1;i<=n;++i)
    {
        sort(row[i].begin(), row[i].end());
    }

    for(int i=1;i<=m;++i)
    {
        sort(col[i].begin(), col[i].end());
    }

    int beg_row=1,beg_col=1,end_row=n,end_col=m;
    int beg_row_last=1,beg_col_last=1,end_row_last=n,end_col_last=m;
    int dir = 0;
    int i=1,j=1;
    int done=1;

    while(beg_row<=end_row && beg_col<=end_col)
    {
        if(dir==0)
        {
            auto it = upper_bound(row[i].begin(), row[i].end(),j);

            int turn;

            if(it==row[i].end() || (*it)>end_col)
            {
                turn = end_col;
            }
            else
            {
                turn = (*it)-1;
            }

            done += turn-j;
            dir=1;
            j=turn;
            end_col=turn;
            beg_row++;
        }

        else if(dir==1)
        {
            auto it = upper_bound(col[j].begin(), col[j].end(),i);

            int turn;

            if(it==col[j].end() || (*it)>end_row)
            {
                turn = end_row;
            }
            else
            {
                turn = (*it)-1;
            }

            done += turn-i;
            dir=2;
            i = turn;
            end_row = turn;
            end_col--;
        }

        else if(dir==2)
        {
            auto it = lower_bound(row[i].begin(), row[i].end(),j);

            int turn;

            if(it==row[i].begin() || *(--it)<beg_col)
            {
                turn = beg_col;
            }

            else
            {
                turn = (*it)+1;
            }

            done += j-turn;
            dir=3;
            j = turn;
            beg_col = turn;
            end_row--;
        }

        else if(dir==3)
        {
            auto it = lower_bound(col[j].begin(), col[j].end(),i);

            int turn;

            if(it==col[j].begin() || *(--it)<beg_row)
            {
                turn = beg_row;
            }

            else
            {
                turn = (*it)+1;
            }

            done += i - turn;
            dir=0;
            i = turn;
            beg_row = turn;
            beg_col++;
        }

        if(beg_row==beg_row_last && beg_col==beg_col_last && end_col==end_col_last && end_row==end_row_last)
        {
            break;
        }

        else
        {
            beg_row_last=beg_row;
            beg_col_last=beg_col;
            end_row_last=end_row;
            end_col_last=end_col;
        }
        /*cout<<done<<'\n';

        if(done==5)
            cout<<beg_row<<' '<<end_row<<' '<<beg_col<<' '<<end_col<<'\n';*/
    }

    if(done==cover)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}