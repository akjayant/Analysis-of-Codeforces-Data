#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
int n, m, k;
vector<int> row[MAX];
vector<int> col[MAX];
int upper_row, lower_row;
int upper_col, lower_col;

int cnt = 0;

pair<int, int> row_for(int x, int y)
{
    int it = upper_bound(row[x].begin(), row[x].end(), y) - row[x].begin();
    int newX = x, newY = min(row[x][it]-1, upper_col-1);
    cnt += abs(newX-x) + abs(newY-y);
    upper_row = x;
    return make_pair(newX, newY);
}

pair<int, int> row_back(int x, int y)
{
    int it = lower_bound(row[x].begin(), row[x].end(), y) - row[x].begin();
    it--;
    int newX = x, newY = max(row[x][it]+1, lower_col+1);
    cnt += abs(newX-x) + abs(newY-y);
    lower_row = x;
    return make_pair(newX, newY);
}

pair<int, int> col_for(int x, int y)
{
    int it = upper_bound(col[y].begin(), col[y].end(), x) - col[y].begin();
    int newX = min(col[y][it]-1, lower_row-1), newY = y;
    //cout << col[y][it] << endl;
    //cout << "HIGH" << col[y][it]-1 << " " << lower_row-1 << endl;
    cnt += abs(newX-x) + abs(newY-y);
    upper_col = y;
    return make_pair(newX, newY);
}

pair<int, int> col_back(int x, int y)
{
    int it = lower_bound(col[y].begin(), col[y].end(), x) - col[y].begin();
    it--;
    int newX = max(col[y][it]+1, upper_row+1), newY = y;
    cnt += abs(newX-x) + abs(newY-y);
    lower_col = y;
    return make_pair(newX, newY);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    upper_row = 0, lower_row = n+1, lower_col = 0, upper_col = m+1;
    for(int i=0; i<k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        row[x].push_back(y);
        col[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        row[i].push_back(0);
        row[i].push_back(m+1);
        sort(row[i].begin(), row[i].end());
    }
    for(int i=1; i<=m; i++){
        col[i].push_back(0);
        col[i].push_back(n+1);
        sort(col[i].begin(), col[i].end());
    }
    int type = 0;
    int x1 = 1, y1 = 1;
    pair<int, int> P = row_for(x1, y1);
    x1 = P.first, y1 = P.second;
    int hi = 0;
    while(true){
        //cout << x1 << " " << y1 << endl;
        type++;
        type = type%4;
        pair<int, int> P;
        if(type == 0) P = row_for(x1, y1);
        else if(type == 1) P = col_for(x1, y1);
        else if(type == 2) P = row_back(x1, y1);
        else P = col_back(x1, y1);
        int x2 = P.first, y2 = P.second;
        if(x2 == x1 && y2 == y1) break;
        else {
            x1 = x2, y1 = y2;
        }
    }
    if(cnt + k + 1 == n*m) cout << "Yes";
    else cout << "No";
}