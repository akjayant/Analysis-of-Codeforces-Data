#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;
vector < ll > perrow[200000], percol[200000];

int main()
{
    cin >> n >> m >> k;
    for(ll i = 1; i <= k; i++){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        perrow[x].push_back(y);
        percol[y].push_back(x);
    }

    ll upr = 1, dwn = n, lft = 1, rgh = m;


    for(ll i = 1; i <= n; i++) {
        perrow[i].push_back(0);
        perrow[i].push_back(m + 1);
        sort(perrow[i].begin(), perrow[i].end());
    }
    for(ll i = 1; i <= m; i++) {
        percol[i].push_back(0);
        percol[i].push_back(n + 1);
        sort(percol[i].begin(), percol[i].end());
    }

    ll curmove = 0, tot = 0;

    while(true){

        if(upr > dwn || lft > rgh) break;

        ///going right
        if(curmove == 0){

            ll poss = upper_bound(perrow[upr].begin(), perrow[upr].end(), lft - 1) - perrow[upr].begin();
            ll nwrgh = perrow[upr][poss] - 1;
            nwrgh = min(nwrgh, rgh);

            tot += nwrgh - lft + 1;

            rgh = nwrgh;
            upr++;
        }

        ///going down
        else if(curmove == 1){
            ll poss = upper_bound(percol[rgh].begin(), percol[rgh].end(), upr - 1) - percol[rgh].begin();
            ll nwdwn = percol[rgh][poss] - 1;
            nwdwn = min(nwdwn, dwn);

            tot += nwdwn - upr + 1;

            dwn = nwdwn;
            rgh--;
        }
        ///going left
        else if(curmove == 2){
            ll poss = lower_bound(perrow[dwn].begin(), perrow[dwn].end(), rgh + 1) - perrow[dwn].begin();
            poss--;
            ll nwlft = perrow[dwn][poss] + 1;
            nwlft = max(nwlft, lft);

            tot += rgh - nwlft + 1;

            lft = nwlft;
            dwn--;
        }

        else{

            ll poss = lower_bound(percol[lft].begin(), percol[lft].end(), dwn + 1) - percol[lft].begin();
            poss--;
            ll nwupr = percol[lft][poss] + 1;
            nwupr = max(upr, nwupr);

//            cout << "yo : " << lft << ' ' << dwn << ' ' << percol[lft][poss] << endl;

            tot += dwn - nwupr + 1;

            upr = nwupr;
            lft++;
        }

//        cout << curmove << ' ' << tot << endl;

        curmove = (curmove + 1) % 4;
    }
//    cout << tot << endl;
    if(tot != n * m - k){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}
