#include <iostream>
#include <stdlib.h> // atoi 함수
#include <cstring>  // strlen 함수
#include <vector>
#include <string>
using namespace std;

#define MAX 1004000

bool primes[MAX];
int findNextPalindrome(int n);
bool isPalindrome(int n);
char* myItoa(int n);

int main() {
    int n;
    cin >> n;

    // 에라토스 테네스의 채를 이용하여 소수를 일단 다 구한다.
    for (int i = 0; i < MAX; i++)
        primes[i] = true;
    primes[0] = primes[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (!primes[i])
            continue;
        for (int j = i * 2; j < MAX; j += i) {
            primes[j] = false;
        }
    }

    int palindrome = n;

    while(true) {
        if (primes[palindrome] && isPalindrome(palindrome)) {
            cout << palindrome << endl;
            break;
        }
        palindrome = findNextPalindrome(palindrome);
    }

    return 0;
}

int findNextPalindrome(int n) {
    char* number = myItoa(n);
    int length = strlen(number);

    // 주어진 숫자가 palindrome이 아닐경우, 뒷 자리 숫자들만 수정한 palindrome을 만들어본다.
    if (!isPalindrome(n)) {
        for (int i = 0; i < length / 2; i++) {
            number[length - 1 - i] = number[i];
        }
        int temp = atoi(number);
        // 뒷자리가 앞자리보다 작았을 경우엔 이때 이미 원래 수보다 큰 palindrome이 만들어진다.
        if (temp > n) {
            delete [] number;
            return temp;
        }
        n = temp;
    }

    // 주어진 palindrome보다 큰 palindrome을 찾는다.
    // 9만으로 주어진 숫자일 경우 자리수를 바꾼다. palindrome이므로 절반만 채크.
    bool isNine = true;
    for (int i = 0; i < length / 2 + 1; i++) {
        if (number[i] - '0' != 9) {
            isNine = false;
        }
    }
    if (isNine) {
        delete [] number;
        return n + 2;
    }

    // // 한자리 숫자가 아니면서 number[0]가 짝수인 경우는 무조건 소수가 아니기 때문에 number[0]의 수가 홀수인 최소의 수를 반환한다.
    // if (length > 1 && number[0] % 2 == 0) {
    //     n = number[0] - '0' + 1;
    //     for (int i = 0; i < length - 1; i++) {
    //         n *= 10;
    //     }
    //     n += number[0] - '0' + 1;
    //     delete [] number;
    //     return n;
    // }

    int index = (length % 2 == 0) ? length / 2 : length / 2 + 1;
    while (true) {
        if (number[index - 1] != '9') {
            number[index - 1] += 1;
            number[length - index] = number[index - 1];
            break;
        } else {    // 올림을 해야 하는 경우
            // 맨 앞자리인데 9인경우는 이미 isNine에서 걸렀다.
            number[index - 1] = number[length - index] = '0';
            index--;
        }
    }

    n = atoi(number);
    delete [] number;
    return n;
}

bool isPalindrome(int n) {
    string number = to_string(n);
    for (int i = 0; i < number.size() / 2; i++) {
        if (number.at(i) != number.at(number.size() - 1 - i)) {
            return false;
        }
    }
    return true;
}

char* myItoa(int n) {
    int temp = n;
    int length = 1;
    while (temp /= 10) {
        length++;
    }
    char* number = new char[length];
    for (int i = 0; i < length; i++) {
        number[length - 1 - i] = n % 10 + '0';
        n /= 10;
    }
    return number;
}