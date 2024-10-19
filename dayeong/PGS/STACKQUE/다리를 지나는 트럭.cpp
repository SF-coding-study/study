#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1; // 총 경과 시간
    
    queue<int> on_bridge; // 다리 위의 트럭
    queue<int> on_sec; // 다리 위에 올라온 시간
    
    on_bridge.push(truck_weights[0]); // 첫 트럭을 다리에 올림
    on_sec.push(1); // 첫 트럭이 다리 위에 올라온 시간
    
    int next_truck = 1;
    int sum_bridge = on_bridge.front(); // 다리 위 트럭들의 무게 합
    
    while(!(next_truck == truck_weights.size() && on_bridge.empty())){
        
        // 다리 위 트럭들이 다리 길이만큼 이동했는지 확인
        if(on_sec.front() == bridge_length){
            sum_bridge -= on_bridge.front(); // 다리를 다 건넌 트럭의 무게를 뺌
            on_bridge.pop();
            on_sec.pop();
        }
        
        // 다음 트럭이 다리에 올라갈 수 있는지 확인
        if((next_truck < truck_weights.size())&&(sum_bridge + truck_weights[next_truck] <= weight)){
            on_bridge.push(truck_weights[next_truck]); //트럭을 다리에 올림
            on_sec.push(0);
            sum_bridge += truck_weights[next_truck]; // 다리 위의 무게 합산
            next_truck++;
        }
        
        // 다리 위에 있는 트럭의 시간을 1씩 증가
        int size = on_sec.size();
        for(int i = 0; i < size; i++){
            int val = on_sec.front();
            on_sec.pop();
            on_sec.push(val+1);
        }
        
        answer++;
        
    }
    
    return answer;
}