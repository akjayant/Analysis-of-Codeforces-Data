#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int> > adjacency(n );
    vector<vector<long long int> > cost(3,vector<long long int>(n));
    for(int c=0;c<n;c++) cin>>cost[0][c];
    for(int c=0;c<n;c++) cin>>cost[1][c];
    for(int c=0;c<n;c++) cin>>cost[2][c];


    int maxi = 0;
    for(int i=0;i<n-1;i++) {
        int f,t;
        cin>>f>>t;
        f--;
        t--;
        adjacency[f].push_back(t);
        adjacency[t].push_back(f);
        maxi = max(maxi, (int)adjacency[f].size());
        maxi = max(maxi, (int)adjacency[t].size());
    }

    if(maxi >= 3) {
        cout<<-1;
        return 0;
    }


    int leaf = 0;
    for(int c=0;c<adjacency.size();c++) {
        if(adjacency[c].size()==1) {
            leaf = c;
            break;
        }
    }

    long long res = -1;
    vector<long long> bestColors(n);

    for(int col1=0;col1<3;col1++) {
        for(int col2=0;col2<3;col2++) {
            if(col1 == col2) continue;
            vector<long long> colors(n);
            int col3 = 0;
            for(int i = 0; i < 3; i++) if(i!=col1&&i!=col2) col3=i;
            long long currentCost = 0;
            long long act = leaf;
            int seen = 0;
            int prec = leaf;
            int toogle = 0;
            while(seen != n) {
                if(toogle==0) {colors[act]=col1+1;currentCost+=cost[col1][act];}
                else if(toogle==1) {colors[act]=col2+1;currentCost+=cost[col2][act];}
                if(toogle==2) {colors[act]=col3+1;currentCost+=cost[col3][act];}
                seen++;
                for(int a=0;a<adjacency[act].size();a++) {
                    int n2 = adjacency[act][a];
                    if(n2 != prec) {
                        prec = act;
                        act = n2;
                        break;
                    }
                }
                toogle++;
                if(toogle == 3) toogle = 0;
            }
            if(res==-1 || res > currentCost) {
                res = currentCost;
                copy(colors.begin(),colors.end(),bestColors.begin());
            }
        }
    }
    cout<<res<<endl;
    for(int c=0;c<bestColors.size();c++) cout<<bestColors[c]<<" ";
}
