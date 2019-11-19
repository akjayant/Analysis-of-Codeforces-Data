/*
ID: Miminyte500
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <utility>

using namespace std;

long long n = 100000;

vector<vector<long long>> cost(3, vector<long long>(n)), el(n);
vector<long long> rez;
vector<long long> boja(n, -1);

int main()
{
    ios_base::sync_with_stdio(0);

    long long a, b;

    cin >> n;



    for(long long i=0;i<3;i++) {
        for(long long j=0;j<n;j++) {
            cin >> cost[i][j];
        }
    }

    for(long long i=0;i<n-1;i++) {
        cin >> a >> b;
        a--;
        b--;
        el[a].push_back(b);
        el[b].push_back(a);
    }

    long long poc;

    for(long long i=0;i<n;i++) {
        if(el[i].size() > 2) {
            cout << -1;
            return 0;
        }
        else if(el[i].size() == 1) {
            poc = i;
        }
    }

    long long mn = 1<<29;
    mn*=mn;

    vector<long long> perm(3);
    perm[0]=0;
    perm[1]=1;
    perm[2]=2;



    do {

        for(int i=0;i<n;i++) boja[i] = -1;

        boja[poc] = perm[0];
        long long tc = 0, tren = poc;

        tc += cost[perm[0]][poc];

        for(long long i=1;i<n;i++) {
            if(boja[el[tren][0]] != -1) swap(el[tren][0], el[tren][1]);

            tren = el[tren][0];

            boja[tren] = perm[i%3];
            tc += cost[perm[i%3]][tren];
        }

        if(tc < mn) {
            mn = tc;
            rez = boja;
        }

    } while(next_permutation(perm.begin(), perm.end()));

    cout << mn << '\n';

    for(long long i=0;i<n;i++) {
        cout << rez[i]+1 << ' ';
    }

    return 0;
}
