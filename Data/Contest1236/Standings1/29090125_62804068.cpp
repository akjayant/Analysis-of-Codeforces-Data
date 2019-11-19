#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <bitset>
#include <list>
#define MOD 1000000000
#define INF 1000000007

using namespace std;

typedef pair<int, int> pii;

int n, m, k, a, b;
long long int cnt;
int rowMin, rowMax, colMin, colMax, curX, curY, dir;
set<int> obsRow[110000];
set<int> obsCol[110000];

void in() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        obsRow[a].insert(b);
        obsCol[b].insert(a);
    }
    rowMin = 1, rowMax = n, colMin = 1, colMax = m, curX = 1, curY = 1, dir = 1;
}

int main() {
    in();
    while (rowMin <= rowMax && colMin <= colMax) {
        if (dir == 1) {
            obsRow[curX].erase(obsRow[curX].begin(), obsRow[curX].lower_bound(colMin));
            obsRow[curX].erase(obsRow[curX].upper_bound(colMax), obsRow[curX].end());
            if (obsRow[curX].empty()) curY = colMax;
            else {
                curY = *(obsRow[curX].begin()) - 1;
                for (int i = curY + 1; i <= colMax; i++) cnt += (rowMax - rowMin + 1);
                colMax = curY;
            }
            rowMin++;
            dir = 2;
        }
        else if (dir == 2) {
            obsCol[curY].erase(obsCol[curY].begin(), obsCol[curY].lower_bound(rowMin));
            obsCol[curY].erase(obsCol[curY].upper_bound(rowMax), obsCol[curY].end());
            if (obsCol[curY].empty()) curX = rowMax;
            else {
                curX = *(obsCol[curY].begin()) - 1;
                for (int i = curX + 1; i <= rowMax; i++) cnt += (colMax - colMin + 1);
                rowMax = curX;
            }
            colMax--;
            dir = 3;
        }
        else if (dir == 3) {
            obsRow[curX].erase(obsRow[curX].begin(), obsRow[curX].lower_bound(colMin));
            obsRow[curX].erase(obsRow[curX].upper_bound(colMax), obsRow[curX].end());
            if (obsRow[curX].empty()) curY = colMin;
            else {
                curY = *(obsRow[curX].rbegin()) + 1;
                for (int i = colMin; i < curY; i++) cnt += (rowMax - rowMin + 1);
                colMin = curY;
            }
            rowMax--;
            dir = 4;
        }
        else {
            obsCol[curY].erase(obsCol[curY].begin(), obsCol[curY].lower_bound(rowMin));
            obsCol[curY].erase(obsCol[curY].upper_bound(rowMax), obsCol[curY].end());
            if (obsCol[curY].empty()) curX = rowMin;
            else {
                curX = *(obsCol[curY].rbegin()) + 1;
                for (int i = rowMin; i < curX; i++) cnt += (colMax - colMin + 1);
                rowMin = curX;
            }
            colMin++;
            dir = 1;
        }
    }
    if (cnt == k) printf("Yes\n");
    else printf("No\n");
}