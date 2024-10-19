#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i = 0; i < commands.size(); i++) {
        int start = commands[i][0] - 1; // 시작 인덱스 (0-indexed)
        int n = commands[i][1];         // 끝 인덱스 (1-indexed)
        int index = commands[i][2] - 1; // k번째 수 (0-indexed)
        vector<int> temp;

        for (int j = start; j < n; j++){ //부분 배열
            temp.push_back(array[j]);
        }

        sort(temp.begin(), temp.end());

        answer.push_back(temp[index]); // k번째 수 추가
    }

    return answer;
}
