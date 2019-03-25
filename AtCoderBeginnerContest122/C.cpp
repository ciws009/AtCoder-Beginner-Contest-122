#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int len = s.size();

    vector<int> l(q), r(q);
    for(int i = 0; i < q; i++) cin >> l[i] >> r[i];

    vector<int> sum(len + 1, 0);

    for(int i = 1; i < len; i++) {
        if(s[i - 1] == 'A' && s[i] == 'C') sum[i + 1] = sum[i] + 1;
        else sum[i + 1] = sum[i];
    }

    for(int i = 0; i < q; i++) {
        int ans = sum[r[i]] - sum[l[i]];
        cout << ans << endl;
    }
}
