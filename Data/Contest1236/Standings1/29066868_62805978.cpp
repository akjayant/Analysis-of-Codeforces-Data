#include<bits/stdc++.h>
using namespace std;

int n, m;
int ara[500][500];

int main()
{
    cin >> n;
    int cur = 1;

    for(int i = 1; i <= n; i++){

        if(i % 2){
            for(int j = 1; j <= n; j++) ara[j][i] = cur++;
        }
        else for(int j = n; j >= 1; j--) ara[j][i] = cur++;

    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) printf("%d ", ara[i][j]);
        printf("\n");
    }

    return 0;
}
