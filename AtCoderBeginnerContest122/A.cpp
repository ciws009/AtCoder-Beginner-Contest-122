#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s; cin >> s;
    string before = "ATCG";
    string after = "TAGC";

    map<char, char> m;
    for(int i = 0; i < before.size(); i++) {
        m[before[i]] = after[i];
    }

    char ans = m[s[0]];

    cout << ans << endl;
}
