#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxWidth = 0;
    int maxHeight = 0;

    for (auto& size : sizes) {
        int width = max(size[0], size[1]);
        int height = min(size[0], size[1]);

        maxWidth = max(maxWidth, width);
        maxHeight = max(maxHeight, height);
    }

    return maxWidth * maxHeight;
}