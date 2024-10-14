#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> clothingCount; 

    int i = 0; 
    for (; i < clothes.size(); i++) {
        string type = clothes[i][1];
        clothingCount[type]++; 
    }

    int answer = 1; 

    auto it = clothingCount.begin(); 
    for (; it != clothingCount.end(); it++) {
        answer *= (it->second + 1); 
    }

    return answer - 1; 
}
