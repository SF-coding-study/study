#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
 
    sort(citations.begin(), citations.end(), greater<int>()); //인용 횟수 내림차순으로 정렬
    
    int hIndex = 0;

    for (int i = 0; i < n; i++) {
        if (citations[i] >= i + 1) { // citations[i] = i번째로 많이 인용된 논문의 인용 횟수
            hIndex = i + 1; 
        } else {
            break; 
    }
    }
    
    return hIndex;
}
