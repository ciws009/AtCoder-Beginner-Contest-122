#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int dp[101][4][4][4];

int main() {
    int n; cin >> n;
    int mod = 1'000'000'007;

    dp[0][3][3][3] = 1;

    for(int len = 0; len < n; len++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    if(dp[len][i][j][k] == 0) continue;
                    for(int a = 0; a < 4; a++) {
                        if(a == 2 && i == 1 && j == 0) continue;
                        if(a == 2 && i == 0 && j == 1) continue;
                        if(a == 1 && i == 2 && j == 0) continue;
                        if(a == 2 && i == 1 && k == 0) continue;
                        if(a == 2 && j == 1 && k == 0) continue;

                        dp[len + 1][a][i][j] += dp[len][i][j][k];
                        dp[len + 1][a][i][j] %= mod;
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int len = 0; len < n; len++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    ans += dp[n][i][j][k];
                    ans %= mod;
                }
            }
        }
    }

    cout << ans << endl;
}
