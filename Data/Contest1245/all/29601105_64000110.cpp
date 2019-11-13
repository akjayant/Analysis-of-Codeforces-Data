#include <cstdio>

using namespace std;

const int MAXN = 111;

char bob[MAXN], alice[MAXN];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; ++t) {
        int n, rock, paper, scissors;
        scanf("%d", &n);
        scanf("%d %d %d", &rock, &paper, &scissors);
        scanf("%s", bob);

        int win = 0;
        for (int i = 0; i < n; ++i) {
            if (bob[i] == 'R' && paper > 0) {
                paper--;
                alice[i] = 'P';
                win++;
            } else if (bob[i] == 'P' && scissors > 0) {
                scissors--;
                alice[i] = 'S';
                win++;
            } else if (bob[i] == 'S' && rock > 0) {
                rock--;
                alice[i] = 'R';
                win++;
            } else {
                alice[i] = 'q';
            }
        }
        alice[n] = 0;
        for (int i = 0; i < n; ++i) {
            if (alice[i] == 'q') {
                if (paper > 0) {
                    paper--;
                    alice[i] = 'P';
                } else if (rock > 0) {
                    rock--;
                    alice[i] = 'R';
                } else {
                    scissors--;
                    alice[i] = 'S';
                }
            }
        }
        
        if (win * 2 >= n) {
            printf("YES\n");
            printf("%s\n", alice);
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
