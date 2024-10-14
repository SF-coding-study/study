#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int solution(vector<int> nums) {
    int N = nums.size();
    int N_2 = N / 2;

    vector<int> types(N);
    int count = 0;

    for (int i = 0; i < N; i++) {
        int num = nums[i];
        bool isNew = true; 

        for (int j = 0; j < count; j++) {
            if (types[j] == num) { 
                isNew = false; 
                break;
            }
        }

        if (isNew) {
            types[count] = num; 
            count++; 
        }
    }

    return min(count, N_2); 
}
