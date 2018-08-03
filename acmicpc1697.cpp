// 숨박꼭질
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << 0 << endl;
        return 0;
    }

    // DP의 데이터 저장용 배열 생성
    const int LENGTH = 100000 + 2;
    int arrivalTimes[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        arrivalTimes[i] = -1;
    }
    arrivalTimes[n] = 0;

    int seconds = 0;
    vector<int> currentLocation;    // 수빈이가 가능한 위치
    currentLocation.push_back(n);
    while (true) {
        seconds++;
        int currentLength = currentLocation.size();
        for (int i = 0; i < currentLength; i++) {
            int subin = currentLocation.at(0);
            currentLocation.erase(currentLocation.begin());

            // 수빈이가 도착하면 끝.
            if (subin == k) {
                cout << arrivalTimes[subin] << endl;
                return 0;
            }

            if (subin > 0 && arrivalTimes[subin - 1] == -1) {
                arrivalTimes[subin - 1] = seconds;
                currentLocation.push_back(subin - 1);
            }
            if (subin + 1 < LENGTH && arrivalTimes[subin + 1] == -1) {
                arrivalTimes[subin + 1] = seconds;
                currentLocation.push_back(subin + 1);
            }
            if (subin * 2 < LENGTH && arrivalTimes[subin * 2] == -1) {
                arrivalTimes[subin * 2] = seconds;
                currentLocation.push_back(subin * 2);
            }
        }
    }

    return 0;
}