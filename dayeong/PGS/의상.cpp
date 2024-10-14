#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {    
    unordered_map<string, vector<string>> clothes_map;
    
    // 각 카테고리별로 의류 아이템을 저장
    for (const vector<string>& item : clothes) {
        clothes_map[item[1]].push_back(item[0]);
    }
    
    int answer = 1;
    
    // nCr * nCr ...
    for (const auto& pair : clothes_map) {
        answer *= (pair.second.size() + 1);
    }
    
    return answer - 1;
}