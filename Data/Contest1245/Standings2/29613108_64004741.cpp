#include<iostream>

using namespace std;

char answer[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        int r, p, s;
        cin >> r >> p >> s;

        string S;
        cin >> S;

        int wins = 0;

        for(int i = 0;i<n;i++)
        {
            answer[i] = '-';

            if(S[i]=='R')
            {
                if(p>0)
                {
                    p--;
                    wins++;
                    answer[i] = 'P';
                }
            }
            else if(S[i]=='P')
            {
                if(s>0)
                {
                    s--;
                    wins++;
                    answer[i] = 'S';
                }
            }
            else
            {
                if(r>0)
                {
                    r--;
                    wins++;
                    answer[i] = 'R';
                }
            }
        }

        for(int i = 0;i<n;i++)
        {
            if(answer[i]=='-')
            {
                if(r>0) {r--;answer[i] = 'R';}
                else if(p>0) {p--;answer[i] = 'P';}
                else if(s>0) {s--;answer[i] = 'S';}
            }
        }

        if(wins*2>=n)
        {
            cout << "YES" << '\n';
            for(int i = 0;i<n;i++) cout << answer[i];
            cout << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
