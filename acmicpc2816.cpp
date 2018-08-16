// 디지털 티비
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, kbs1, kbs2;
    kbs1 = kbs2 = -1;
    cin >> n;
    string chenel;
    for (int i = 0; i < n; i++) {
        cin >> chenel;
        if (kbs1 == -1 && chenel == "KBS1")
            kbs1= i;
        else if (kbs2 == -1 && chenel == "KBS2")
            kbs2 = i;
    }
    
    int small = kbs1 > kbs2 ? kbs2 : kbs1;
    int big = kbs1 > kbs2 ? kbs1 : kbs2;

    // small까지 화살표를 내린다.
    for (int i = 0; i < small; i++) {
        cout << "1";
    }
    // small을 0번까지 올린다.
    for (int i = 0; i < small; i++) {
        cout << "4";
    }
    // 화살표를 big까지 내린다.
    for (int i = 0; i < big; i++) {
        cout << "1";
    }
    // big이 KBS1이면 0까지, 아니면 1까지 끌어올린다.
    if (big == kbs2)
        big--;
    for (int i = 0; i < big; i++) {
        cout << "4";
    }
    cout << endl;

    return 0;
}