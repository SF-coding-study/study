#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    int base_i = 0;
    vector<int> num_list = {0, 5, 50, 55};
    int num = 0;
    bool flag = true;
    
    while(flag){
        vector<int> new_nums;
        
        int base;
        base = (base_i == 0) ? 0 : 500 * static_cast<int>(pow(10, base_i - 1));
        
        for(int i = 0; i < num_list.size(); i++){
            num = base + num_list[i];
            if(num > r){
                flag = false;
                break;
            }
            if(num >= l)
                answer.push_back(num);
            if(base > 0)
                new_nums.push_back(num);
            
        }
        
        for(int n : new_nums)
            num_list.push_back(n);
        
        base_i++;
    }
    
    if(answer.empty())
        answer.push_back(-1);
        
    return answer;

}