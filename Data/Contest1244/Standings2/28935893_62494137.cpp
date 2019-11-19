#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100000;
int n;
vector<int> el[maxn];
int c[3][maxn], foksz[maxn], szam[maxn];
int fmax, gyok;
long long szcs[3][3];

void debug() {
    cout<<'\n';
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout<<szcs[i][j]<<' ';
        } cout<<'\n';
    } cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (int ii=0; ii<3; ii++) {
        for (int i=0; i<n; i++) cin>>c[ii][i];
    }
    int a,b;
    for (int i=1; i<n; i++) {
        cin>>a>>b; a--; b--;
        foksz[a]++; foksz[b]++;
        el[a].push_back(b);
        el[b].push_back(a);
    }
    for (int i=0; i<n; i++) {
        fmax = max(fmax, foksz[i]);
        if (foksz[i]==1) gyok = i;
    }
    if (fmax > 2) {
        cout<<"-1\n";
        return 0;
    }
    foksz[gyok] = 0;
    szam[gyok] = 0;
    for (int i=0; i<3; i++) {
        szcs[i][szam[gyok]] += c[i][gyok];
    }
    int elo = -1, sz = 1;
    int k = gyok;
    while (foksz[k]!=1) {
        for (int i:el[k]) if (i!=elo) {
            elo = k;
            k = i;
            break;
        }
        szam[k] = sz;
        for (int i=0; i<3; i++) {
            szcs[i][szam[k]] += c[i][k];
        }
        sz = (sz+1)%3;
    }

    //debug();
    int mi,mj,mk; long long mcost = 10000000000000000;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) if (j!=i) {
            for (int k=0; k<3; k++) if (k!=i && k!=j) {
                long long cost = szcs[i][0] + szcs[j][1] + szcs[k][2];
                if (cost < mcost) {
                    mcost = cost;
                    mi = i; mj = j; mk = k;
                }
            }
        }
    }
    cout<< mcost <<'\n';
    for (int i=0; i<n; i++) {
        if (szam[i]==0) cout<<mi+1<<' ';
        else if (szam[i]==1) cout<<mj+1<<' ';
        else /*if (szam[i]==2)*/ cout<<mk+1<<' ';
    } cout<<'\n';

    return 0;
}
