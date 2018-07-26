#include <iostream>
#include <string>
using namespace std;

string reverseTree(string tree);
int getElementLength(string tree);

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        string input;
        cin >> input;
        cout << reverseTree(input) << endl;
    }
}

string reverseTree(string tree) {
    // 흰색이나 검은색 하나로 구성된 base condition.
    if (tree.length() == 1) {
        return tree;
    }

    // tree[0] == 'x'
    // 각 네 귀퉁이의 길이를 구한다.
    int leftUp = getElementLength(tree.substr(1));
    int rightUp = getElementLength(tree.substr(1 + leftUp));
    int leftDown = getElementLength(tree.substr(1 + leftUp + rightUp));
    string first = reverseTree(tree.substr(1, leftUp));
    string second = reverseTree(tree.substr(1 + leftUp, rightUp));
    string third = reverseTree(tree.substr(1 + leftUp + rightUp, leftDown));
    string fourth = reverseTree(tree.substr(1 + leftUp + rightUp + leftDown));

    return "x" + third + fourth + first + second;
}

int getElementLength(string tree) {
    int index = 1;
    int check = 0;
    while (check < index) {
        if (tree.at(check) == 'x') {
            index += 4;
        }
        check++;
    }
    return index;
}