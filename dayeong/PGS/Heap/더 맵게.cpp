#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0;
    
    while (pq.size() > 1 && pq.top() < K) {
        int min1 = pq.top(); // 가장 작은 값
        pq.pop();
        int min2 = pq.top(); // 두 번째로 작은 값
        pq.pop();

        int newScoville = min1 + (min2 * 2);
        pq.push(newScoville); // 새 스코빌 지수 추가
        answer++;

        if (pq.top() >= K) { // 가장 작은 값이 K 이상이면 종료
            return answer;
        }
    }

    // 모든 경우를 조합해도 K에 도달하지 못하는 경우
    return pq.top() >= K ? answer : -1;
}