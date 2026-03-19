#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string vowels = "aeyiou";
 
    string word;
    cin >> word;
 
    string resultado;
 
    // checking for vowels and consonants
    for (auto& c: word) {
        c = tolower(c);
        
        if (vowels.find(c) > 5) {
            resultado += '.';
            resultado += c;
        }
    }
    cout << resultado << endl;
 
    return 0;
}