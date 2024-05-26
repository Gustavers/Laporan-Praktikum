#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    // Mengubah huruf menjadi huruf kecil 
    c = tolower(c);
    // Memeriksa apakah karakter adalah huruf vokal
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(string sentence) {
    int count = 0;
    // Menghitung jumlah huruf vokal 
    for (char c : sentence) {
        if (isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);
    int vowelCount = countVowels(sentence);
    cout << "Jumlah huruf vokal : " << vowelCount << endl;
    return 0;
}
