//404 Not Found {=}7 (o)7 (x)7
#include<bits/stdc++.h>
using namespace std;
#define append push_back
#define endl "\n"
#define dbug(x) cout<<#x<<"="<<x<<endl

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5+10, inf = 1e9, mod= 1e9+7;
int col[maxn][3];
vector <int > adl[maxn],path;
vector < pii > ansss;

ll root,anss=1e18,ans,ansi;
int hal[6][3] = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};

void dfs(int x,int p =-1)
{
    for(int y: adl[x])
    {
        if(y==p)
            continue;
        dfs(y,x);
    }
    path.append(x);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << setprecision(30);
    int n;
    cin >> n;
    for(int i = 0;i<3;i++)
    {
        for(int j = 1;j<=n;j++)
            cin >> col[j][i];
    }
    for(int  i = 0;i<n-1;i++)
    {
        int a,b;
        cin  >> a >> b;
        
        adl[a].append(b);
        adl[b].append(a);
        if(adl[a].size()>2 || adl[b].size()> 2)
        {
            cout << -1;
            return 0;
        }
    }
    for(int i = 0 ;i<n;i++)
    {
        if(adl[i].size()==1)
        {
            root = i;
            break;
        }
    }
    dfs(root);
    for(int  i = 0;i<6;i++)
    {
        ans = 0;
        for(int j =0;j<n;)
        {
            int t = path[j++];
            ans += col[t][hal[i][0]-1];
            if(j>=n)
                break;
            t = path[j++];
            ans += col[t][hal[i][1]-1];
            if(j>=n)
                break;
            t = path[j++];
            ans += col[t][hal[i][2]-1];
            if(j>=n)
                break;
        }
       
        if(ans < anss)
        {
            anss = ans;
            ansi = i;
        }
    }
    for(int j =0;j<n;)
        {
            int t = path[j++];
            ansss.append({t,hal[ansi][0]});
            if(j>=n)
                break;
            t = path[j++];
            ansss.append({t,hal[ansi][1]});
            if(j>=n)
                break;
            t = path[j++];
            ansss.append({t,hal[ansi][2]});
            if(j>=n)
                break;
        }
    sort(ansss.begin(),ansss.end());
    cout << anss << endl;
    for(auto i : ansss)
    {
        cout << i.second << " ";
    }
    return 0;
}