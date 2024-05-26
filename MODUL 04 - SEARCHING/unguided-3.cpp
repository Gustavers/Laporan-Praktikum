#include <iostream>
#include <vector>
using namespace std;

int sequentialSearchCount(vector<int> data, int target) {
    int count = 0;
    for (int num : data) {
        if (num == target) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target = 4;

    int count = sequentialSearchCount(data, target);

    cout << "Banyaknya angka " << target << " dalam data adalah: " << count << endl;

    return 0;
}
