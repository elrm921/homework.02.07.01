#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string input = "Hello, world!!";

    map<char,int> freq;
    for (auto c : input) {
        auto it = freq.find(c);
        if (it == freq.end()) {
            freq.emplace(c,1);
        }
        else {
            it->second++;
        }
    }

    vector<pair<char,int>> output;
    for (auto &n : freq) {
        output.push_back(n);
    }

    auto cmp = [](pair<char,int> &a, pair<char,int> &b) { return a.second > b.second; };
    sort(output.begin(), output.end(), cmp);

    for (auto &n : output) {
        cout << n.first << " " << n.second << "\n";
    }

    return 0;
}