#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
ll n,m,k;
ll need = 0;
ll ans = 0;
vector < int > row[200005];
vector < int > col[200005];
ii X , Y;
int cnt = 0;
ll solve(int i,int j,char dir,int ok)
{
    if(cnt > 1000000)
        return 0 ;
    cnt++;
    if(dir == 'R')
    {
        Y.fr = max(Y.fr , j);
        if(Y.sc < j)
            return 0 ;
        int it = lower_bound(row[i].begin(),row[i].end(),j)-row[i].begin();
        int tar = row[i][it];
        tar--;
        tar = min(tar , Y.sc);
        if(tar == j)
        {
            if(ok)
            {
                 return solve(i,j,'D',0);
            }
            else
                return 0 ;
        }
        else
        {

            return abs(tar-j)+solve(i,tar,'D',0);
        }
    }
    else if(dir == 'L')
    {
        Y.sc = min(Y.sc , j-1);
        if(Y.fr > j)
            return 0 ;
        int it = lower_bound(row[i].begin(),row[i].end(),j)-row[i].begin();
        it--;
        int tar = row[i][it];
        tar++;

        tar = max(tar , Y.fr);
        if(tar == j)
        {
            if(ok)
            {
                return solve(i,j,'U',0);
            }
            else
                return 0 ;
        }
        else
        {
             return abs(tar-j)+solve(i,tar,'U',0);
        }
    }
    else if(dir == 'D')
    {
        if(X.sc < i)
            return 0;
        X.fr = max(X.fr , i+1);
        int it = lower_bound(col[j].begin(),col[j].end(),i)-col[j].begin();
        int tar = col[j][it];
        tar--;
        tar = min(tar , X.sc);
        if(tar == i)
        {
            if(ok)
                return solve(i,j,'L',0);
            else
                return 0 ;
        }
        else
        {
            return abs(tar-i)+solve(tar,j,'L',0);
        }
    }
    else if(dir == 'U')
    {
        if(X.fr > i)
            return 0 ;
        X.sc = min(X.sc , i-1);
        Y.fr = max(Y.fr , j+1);
        int it = lower_bound(col[j].begin(),col[j].end(),i)-col[j].begin();
        it--;
        int tar = col[j][it];
        tar++;
        tar = max(tar , X.fr);

        if(tar == i)
        {
             if(ok)
                return solve(i,j,'R',0);
            else
                return 0 ;
        }
        else
        {
            return abs(tar-i)+solve(tar,j,'R',0);
        }
    }
    return 0 ;
}
int main()
{
    cin>>n>>m>>k;
    need = 1LL * n*m - k;
    need--;
    X = (mp(1,n));
    Y = (mp(1,m));
    for(int i=0; i<k; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        row[x].push_back(y);
        col[y].push_back(x);
    }

    for(int i=1; i<=m; i++)
    {
        col[i].push_back(0);
        col[i].push_back(n+1);
        sort(col[i].begin(),col[i].end());
    }

    for(int i=1; i<=n; i++)
    {
        row[i].push_back(0);
        row[i].push_back(m+1);
        sort(row[i].begin(),row[i].end());
    }
    ll res = solve(1,1,'R',1);
    if(res == need)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}
