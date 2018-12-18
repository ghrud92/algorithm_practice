#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<char> stack;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        bool success = true;
        for (int j = 0; j < line.length(); j++) {
            if (line[j] == '(') {
                stack.push_back('(');
            } else if (stack.size() != 0 && stack.back() == '(') {
                stack.pop_back();
            } else {
                success = false;
                break;
            }
        }
        if (stack.size() > 0) {
            success = false;
        }
        if (success) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        stack.clear();
    }

    return 0;
}