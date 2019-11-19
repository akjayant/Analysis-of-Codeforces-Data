#include <bits/stdc++.h>

using namespace std;

#define MM 1000000007

struct node{
    int i,j;
};



node next(node x){
    node res;
    res = x;
    // cout << "   " << x.i << ' ' << x.j << endl;
    if(x.i%2==0){
        if(x.j-1>=0)
            res.j--;
        else
            res.i--;
    }
    else{
        if(x.j+1<=9)
            res.j++;
        else
            res.i--;
    }
    // cout << "   " << res.i << ' ' << res.j << endl;
    return res;
}

node prev(node x){
    node res;
    res = x;
    if(x.i%2==0){
        if(x.j+1<10)
            res.j++;
        else
            res.i++;
    }
    else{
        if(x.j-1>=0)
            res.j--;
        else
            res.i++;
    }
    return res;
}

// node prev(node x, int xx){
//     node res = x;
//     for(int i=0;i<xx;i++){
//         res = prev(res);
//     }
//     return res;
// }

node next(node x, int xx){
    node res = x;
    for(int i=0;i<xx;i++){
        res = next(res);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;

    int t,T;
    // cin >> T;
    T = 1;


    for(t=1;t<=T;t++){
        int i,j,B[10][10];
        double E[10][10];

        for(i=0;i<10;i++)
            for(j=0;j<10;j++)
                cin >> B[i][j];

        node x;
        x.i=0;
        x.j=6;
        E[0][0] = 0.0;
        E[0][1] = 6.0;
        E[0][2] = 6.0;
        E[0][3] = 6.0;
        E[0][4] = 6.0;
        E[0][5] = 6.0;
        while(x.i<10){
            double summ = 0;
            for(i=1;i<=6;i++){
                node t = next(x,i);
                // cout << t.i << ' ' << t.j << endl; 
                double tt = E[t.i][t.j];
                if(B[t.i][t.j] > 0){
                    tt = min(E[t.i]               [t.j],
                             E[t.i - B[t.i][t.j]] [t.j]);
                }
                summ += tt;
            }
            E[x.i][x.j] = 1 + summ/6.0;
            x = prev(x);
        }
        cout << E[9][0];
    }
    return 0;
}