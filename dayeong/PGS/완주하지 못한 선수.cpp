#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> completion_map;
    
    // 완주자 목록에서 이름을 카운팅
    for(const string& c : completion){
        completion_map[c]++; // 완주자 이름을 해시맵에 저장하고, 카운트를 증가시킴

    }
    
    // 참가자를 순회하며 완주자 확인
    for(const string& p : participant){
        if(completion_map[p] > 0){
            // 카운트가 남아 있으면 1 감소
            completion_map[p]--;
        }
        else{
            answer = p;  // 목록에 없음 또는 동명이인 모두 처리된 경우 (완주하지 못한 참가자)
        }
    }
    
    return answer;
}