#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    string s; cin >> s;
    string t = "ATCG";
    int ans = 0, now = 0;

    for(int i = 0; i < s.size(); i++) {
        bool flag = false;
        for(int j = 0; j < s.size(); j++) {
            if((int)t.find(s[i]) != -1) flag = true; break;
        }
        if(flag) {
            now++;
            ans = max(ans, now);
        } else {
            now = 0;
        }
    }
    cout << ans << endl;
}
