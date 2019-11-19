#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define int long long
using namespace std;

int x[2000], y[2000], k[2000], c[2000];
bool fait[2000];


struct Event
{
    int cout, ville1, ville2;
    bool type;
    
    bool operator < (const Event &autre) const
    {
        return cout > autre.cout;
    }
};

priority_queue<Event> sac;
vector<Event> res1, res2;
int cost;

signed main()
{
    int nbVilles;
    cin >> nbVilles;
    
    for (int iVille = 0; iVille < nbVilles; ++ iVille){
        cin >> x[iVille] >> y[iVille];
    }
    
    
    for (int iVille = 0; iVille < nbVilles; ++ iVille){
        cin >> c[iVille];
        sac.push({c[iVille], iVille, -1, 0});
    }
    for (int iVille = 0; iVille < nbVilles; ++iVille)
        cin >> k[iVille];
    
    
    int nbFaits = 0;
    while (nbFaits != nbVilles)
    {
        Event event = sac.top();
        sac.pop();
        
      //  cout << event.ville1 << " " << event.ville2 << " " <<event.cout << " " << event.type << endl;
        
        if (!event.type)
        {
            if (fait[event.ville1])
                continue;
            fait[event.ville1] = true;
            nbFaits++;
            cost += event.cout;
            res1.push_back({0, event.ville1, 0, 0});
            for (int iVille = 0; iVille < nbVilles; ++ iVille)
                sac.push({(k[iVille] + k[event.ville1]) * (abs(x[iVille] - x[event.ville1]) + abs(y[iVille] - y[event.ville1])), event.ville1, iVille, 1});
        }
        else
        {
            if (fait[event.ville2])
                continue;
            fait[event.ville2] = true;
            cost += event.cout;
            nbFaits++;
            res2.push_back({0, event.ville1, event.ville2, 0});
            for (int iVille = 0; iVille < nbVilles; ++ iVille)
                sac.push({(k[iVille] + k[event.ville2]) * (abs(x[iVille] - x[event.ville2]) + abs(y[iVille] - y[event.ville2])), event.ville2, iVille, 1});
        }
    }
    
    cout << cost << endl;
    cout << res1.size() << endl;
    for (Event a : res1) cout << a.ville1 + 1<< " ";
    cout << endl;
    cout << res2.size() << endl;
    for (Event a : res2) cout << a.ville1 + 1<< " " << a.ville2 + 1<< endl;
    cout << endl;
    
    return 0;
} 