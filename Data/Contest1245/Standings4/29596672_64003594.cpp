#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define num     int

int main()
{
    std::ios_base::sync_with_stdio(false);

    int T;  input >> T;
    while (T--) {
        num rocks, papers, scissors;
        std::string str;
        int N;

        input >> N;
        input >> rocks >> papers >> scissors;
        input >> str;

        num r = 0, p = 0, s = 0;
        for (auto &ch:str)
            if (ch == 'R') r++;
            else if (ch == 'P') p++;
            else if (ch == 'S') s++;

        num cnt = std::min(papers, r) + std::min(scissors, p) + std::min(rocks, s);
        if (cnt >= (N+1)/2) {
            output << "YES\n";
            std::string str2(str.size(), ' ');

            for (int i=0; i<str.size(); ++i)
                if (str[i] == 'R' && papers)
                    -- papers, str2[i] = 'P';
                else if (str[i] == 'P' && scissors)
                    -- scissors, str2[i] = 'S';
                else if (str[i] == 'S' && rocks)
                    -- rocks, str2[i] = 'R';

            for (int i=0; i<str.size(); ++i) if (str2[i] == ' ') {
                if (rocks)
                    -- rocks, str2[i] = 'R';
                else if (papers)
                    -- papers, str2[i] = 'P';
                else if (scissors)
                    -- scissors, str2[i] = 'S';
            }   output << str2 << '\n';
        }
        else {
            output << "NO\n";
        }
    }

    return 0;
}
