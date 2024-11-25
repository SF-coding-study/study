#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end()); // 순열 탐색을 위한 정렬

    // 모든 순열 탐색
    do {
        int currentE = k; // 현재 남은 피로도
        int count = 0;   // 현재 순열로 탐험한 던전 수

        for (const auto& dungeon : dungeons) {
            int required = dungeon[0]; // 최소 필요 피로도
            int consume = dungeon[1];  // 소모 피로도

            if (currentE >= required) { // 탐험 가능 조건
                currentE -= consume;
                count++;
            } else {
                break; // 더 이상 탐험 불가
            }
        }

        answer = max(answer, count); // 최대값 갱신
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}