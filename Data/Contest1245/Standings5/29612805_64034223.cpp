#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 42;
const int MAXN = 2005;
const int MOD = 1000000007;

struct {int x,y;} posville[MAXN];
int kcentrale[MAXN];
int kwire[MAXN];

int n;
int dist[MAXN];
int filavec[MAXN];
bool vu[MAXN];

void majdist(int k)
{
    for(int i = 0; i < n; i++){
        int dman = abs(posville[i].x - posville[k].x) + abs(posville[i].y - posville[k].y);
        int icout = dman * (kwire[i] + kwire[k]);
        if(dist[i] > icout){
            dist[i] = icout;
            filavec[i] = k;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> posville[i].x >> posville[i].y;

    for(int i = 0; i < n; i++){
        cin >> kcentrale[i];
        dist[i] = kcentrale[i];
        filavec[i] = -1;
    }
    for(int i = 0; i < n; i++)
        cin >> kwire[i];

    int centmin = 0;
    for(int i = 0; i < n; i++)
        if(kcentrale[i] < kcentrale[centmin])
            centmin = i;
    
    vector<int> centrales;
    vector<pair<int,int>> fils;

    int couttot = kcentrale[centmin];
    vu[centmin] = true;
    centrales.push_back(centmin);

    majdist(centmin);

    for(int step = 0; step < n-1; step++){
        int nouv = 0;
        for(int i = 0; i < n; i++){
            if(vu[nouv] || (dist[i] < dist[nouv] && !vu[i]))
                nouv = i;
        }

        vu[nouv] = true;
        couttot += dist[nouv];
        if(filavec[nouv] == -1)
            centrales.push_back(nouv);
        else
            fils.push_back(make_pair(nouv, filavec[nouv]));
        
        majdist(nouv);
    }

    cout << couttot << "\n";
    cout << centrales.size() << "\n";
    for(int i : centrales)
        cout << i+1 << " ";
    cout << "\n";
    cout << fils.size() << "\n";
    for(auto i : fils)
        cout << i.first+1 << " " << i.second+1 << "\n";
}