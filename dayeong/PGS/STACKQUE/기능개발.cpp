#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    
    while(index < progresses.size()){
        int count = 0;
        int time = (int)ceil((100.0 - progresses[index]) / speeds[index]);
        
        for(int i = index; i < progresses.size(); i++) {
            progresses[i] += speeds[i] * time;
        }
        
        for(int i = index; i < progresses.size(); i++) {
            if(progresses[i] >= 100) {
                count++;
            } else {
                break;  // 완료되지 않은 작업이 나오면 중단
            }
        }
        
        // 완료된 작업 개수만큼 인덱스를 증가시키고 결과에 추가
        index += count;
        answer.push_back(count);
    }
    
    return answer;
}