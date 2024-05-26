#include <iostream>
using namespace std;

int factorialHelper(int n, int result) {
    if (n == 0 || n == 1) {
        return result;
    }
    return factorialHelper(n - 1, n * result);
}

int factorialStart(int n) {
    return factorialHelper(n, 1);
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorialStart(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}
