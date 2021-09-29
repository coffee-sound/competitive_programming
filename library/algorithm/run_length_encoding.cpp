#include <iostream>
#include <vector>
using namespace std;

// ランレングス圧縮
vector<pair<char, int>> RLE(const string &str) {
    vector<pair<char, int>> res;
    char tmp = ' ';
    int cnt = 0;
    for (auto c : str) {
        if (c == tmp) {
            cnt++;
        } else {
            if (tmp != ' ') {
                res.emplace_back(tmp, cnt);
            }
            tmp = c;
            cnt = 1;
        }
    }
    res.emplace_back(tmp, cnt);

    return res;
}