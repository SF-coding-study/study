#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;  // 결과를 저장할 벡터
    
    // commands의 각 명령어를 처리
    for (int i = 0; i < commands.size(); i++) {
        // array의 특정 범위를 추출하여 임시 벡터로 저장
        vector<int> sub_array(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        
        // 추출한 구간을 오름차순으로 정렬
        sort(sub_array.begin(), sub_array.end());
        
        // 정렬된 배열에서 commands[i][2]번째 값을 answer에 추가 (1-based index이므로 -1)
        answer.push_back(sub_array[commands[i][2] - 1]);
    }
    
    return answer;
}