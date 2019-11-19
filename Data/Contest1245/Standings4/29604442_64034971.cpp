#include<iostream>
#include<unordered_map>
#include <iomanip>


using namespace std;

int h[15][15];
int dist[15][15];
double expect[15][15];
unordered_map<int, pair<int, int> > dist2pos;


int main()
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; ++j)
            cin>>h[i][j];
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
        {
            if(i % 2 == 0)
            {
                dist[i][j] = i + j + 9 * i;
            }
            else
            {
                dist[i][j] = i + 9 - j + 9 * i;
            }
            dist2pos[dist[i][j]] = make_pair(i, j);
        }
    bool left = true;
    expect[0][0] = 0.0;
    int x = 0, y = 1;
    while(true)
    {
        double e = 0.0;
        if(dist[x][y] < 6)
        {
            for(int dice = 1; dice <= dist[x][y]; ++dice)
            {
                int xx = dist2pos[dist[x][y] - dice].first;
                int yy = dist2pos[dist[x][y] - dice].second;
                e += (1.0/ 6.0) * (expect[xx][yy]+1);
            }
            e += (6 - dist[x][y]) / 6.0;
            e /= (dist[x][y] / 6.0);
            expect[x][y] = e;
        }
        else
        {
            for(int dice = 1; dice <= min(6, dist[x][y]); ++dice)
            {
                int xx = dist2pos[dist[x][y] - dice].first;
                int yy = dist2pos[dist[x][y] - dice].second;
                double next_e;
                if(h[xx][yy] == 0)
                {
                    next_e = expect[xx][yy];
                }
                else
                {
                    int xxx = xx - h[xx][yy];
                    int yyy = yy;
                    next_e = min(expect[xx][yy], expect[xxx][yyy]);
                }
                e = e + (1.0/ 6.0) * next_e;
            }
            e += 1.0;
            expect[x][y] = e;
        }
        if(x == 9 && y == 0)
            break;
        auto p = dist2pos[dist[x][y]+1];
        x = p.first;
        y = p.second;
    }
    cout<<fixed<<setprecision(6)<<expect[9][0]<<endl;
    return 0;
    
}
