#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> phone_map;
    
    // 모든 전화번호를 해시맵에 저장
    for(const string& p : phone_book){
        phone_map[p]++;
    }
    
    // 각 전화번호에 대해 접두어(prefix)가 해시맵에 존재하는지 확
    for(const string& p : phone_book){
        for(int j = 0; j < p.size(); j++){
            string prefix = p.substr(0,j);
            if(phone_map.count(prefix)){
                return false;
            }
        }
    }
    
    return answer;
}