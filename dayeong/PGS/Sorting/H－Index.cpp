#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    
    // 인용 횟수를 오름차순으로 정렬
    sort(citations.begin(), citations.end());
    
    // H-Index 계산
    for (int i = 0; i < size; i++) {
        // 남은 논문 수가 현재 논문의 인용 횟수 이상인지 확인
        int h = size - i;
        if (citations[i] >= h) {
            answer = h;
            break;
        }
    }
    
    return answer;
}