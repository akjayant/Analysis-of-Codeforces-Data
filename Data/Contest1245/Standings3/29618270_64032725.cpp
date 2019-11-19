#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int>> board(10, vector<int> (10, 0));
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      cin >> board[i][j];
    }
  }
  vector<int> br;
  int sz = 0;
  for(int i = 0; i < 10; i++)
  {
    if(i % 2 == 0)
    {
      for(int j = 0; j < 10; j++)
      {
        if(board[i][j] == 0)
        {
          br.push_back(-1);
        }
        else
        {
          br.push_back(board[i - board[i][j]][j]);
        }
        board[i][j] = sz;
        sz++;
      }
    }
    else
    {
      for(int j = 9; j >= 0; j--)
      {
        if(board[i][j] == 0)
        {
          br.push_back(-1);
        }
        else
        {
          br.push_back(board[i - board[i][j]][j]);
        }
        board[i][j] = sz;
        sz++;
      }
    }
  }
  vector<pair<double, double>> dp(100);
  dp[0].first = dp[0].second = 0;
  dp[1].first = dp[1].second = 6;
  dp[2].first = dp[2].second = 6;
  dp[3].first = dp[3].second = 6;
  dp[4].first = dp[4].second = 6;
  dp[5].first = dp[5].second = 6;
  dp[6].first = dp[6].second = 6;
  for(int i = 7; i < 100; i++)
  {
    double cale = 0;
    for(int j = 1; j <= 6; j++)
    {
      cale += dp[i - j].first + 1;
    }
    cale /= 6;
    if(br[i] == -1)
    {
      dp[i].first = dp[i].second = cale;
    }
    else
    {
      dp[i].second = cale;
      dp[i].first = min(cale, dp[br[i]].second);
    }
  }
  cout << fixed << setprecision(10) << dp[99].second << endl;
  return 0;
}
