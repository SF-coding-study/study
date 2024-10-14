#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (size_t i = 0; i < phone_book.size() - 1; ++i) {
        string current = phone_book[i];
        string next = phone_book[i + 1];

        if (next.substr(0, current.length()) == current) {
            return false; 
        }
    }

    return true;
}

