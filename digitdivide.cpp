// acmicpc 1490번 자리수로 나누기
#include <iostream>
using namespace std;

// 숫자 n에 들어있는 숫자의 종류.
bool digit[10];
int targetLCM;
long findResult(long n);
int gcd (int a, int b);
int lcm (int a, int b);

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++)
        digit[i] = false;
    int temp = n;
    while (temp > 0) {
        digit[temp % 10] = true;
        temp /= 10;
    }

    targetLCM = 1;
    for (int i = 2; i < 10; i++) {
        if (digit[i]) {
            targetLCM = lcm(targetLCM, i);
        }
    }

    cout << findResult(n) << endl;

    return 0;
}

long findResult(long n) {
    if (n % targetLCM == 0) {
        return n;
    }

    int digitNum = 1;
    while (true) {
        int limit = 1;
        for (int i = 0; i < digitNum; i++)
            limit *= 10;

        long result = n * limit;
        for (int i = 0; i < limit; i++) {
            if (result % targetLCM == 0) {
                return result;
            }
            result++;
        }
        
        digitNum++;
    }
}

int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    int temp = gcd(a, b);
    return temp ? (a * b / temp) : 0;
}