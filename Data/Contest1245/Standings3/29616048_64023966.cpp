#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

long long X[3000], Y[3000], C[3000], K[3000], D[3000], V[3000], P[3000], COMP[3000], COMPF[3000];

struct Link {
    int a, b;
    Link(int a, int b) : a(a), b(b) {}
};

vector<Link> LINKS;

int main() {
    ios_base::sync_with_stdio(false);
    
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++) 
            cin >> X[i] >> Y[i];
        for(int i=0; i<N; i++)  {
            cin >> C[i];    
            D[i] = C[i];
        }
        for(int i=0; i<N; i++) 
            cin >> K[i];    
        
        memset(COMP, 0x3f, sizeof COMP);
        memset(V, 0, sizeof D);
        LINKS.clear();
        
        int comps = 0;
        long long total = 0;
        for(int k=0; k<N; k++) {
            int minn = -1;
            for(int i=0; i<N; i++){
                if (V[i] == 0 && (minn < 0 || D[i] < D[minn]))
                    minn = i;
            }
            
            if (D[minn] == C[minn]) {
                V[minn] = ++comps;
                COMP[comps] = C[minn];
                COMPF[comps] = minn;
//                cout << " NEW " << minn << " " << D[minn] << " " << C[minn] << endl;
            } else {
                V[minn] = V[P[minn]];
                total += D[minn];
                if (C[minn] < COMP[comps]) {
                    COMP[comps] = C[minn];
                    COMPF[comps] = minn;
                }
                LINKS.push_back(Link(minn, P[minn]));
//                cout << " LIN " << minn << " " << P[minn] << " " << D[minn] << " " << C[minn] <<endl;
            }
            
            for(int i=0; i<N; i++) {
                long long dist = (abs(X[i]-X[minn])+abs(Y[i]-Y[minn]))*(K[i]+K[minn]);
                if (dist < D[i]) {
                    D[i] = dist;
                    P[i] = minn;
                }
            }
        }
        for(int i=1; i<=comps; i++) {
            total += COMP[i];
        }
        cout << total << endl;

        cout << comps << endl;
        for(int i=1; i<=comps; i++) {
            if (i > 1) cout << " ";
            cout << COMPF[i]+1;
        }
        cout << endl;

        cout << LINKS.size() << endl;

        for(int i=0; i<LINKS.size(); i++) {
            cout << LINKS[i].a+1 << " " << LINKS[i].b+1 << endl;
        }

        
        
        
    }
}