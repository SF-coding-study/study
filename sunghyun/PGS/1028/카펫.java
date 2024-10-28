import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        int sum = (brown - 4) / 2;
        int h = 0;
        for (int i = 1; i <= sum / 2; i++){
            if (i * (sum - i) == yellow) {
                h = i;
                break;
            }
        }
        int[] wh = {sum - h + 2, h + 2};
        return wh;
    }
}