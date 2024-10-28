#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxWidth = 0;  
    int maxHeight = 0; 
    
    for (const auto& size : sizes) {
        int w = max(size[0], size[1]);
        int h = min(size[0], size[1]);
        
        maxWidth = max(maxWidth, w);
        maxHeight = max(maxHeight, h);
    }
    
    return maxWidth * maxHeight;
}
