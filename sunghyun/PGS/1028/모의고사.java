import java.util.*;

class Solution {
    public Integer[] solution(int[] answers) {
        int[][] arr = new int[3][answers.length];
        int[] pattern1 = {1, 2, 3, 4, 5};
        int[] pattern2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] pattern3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        for (int i = 0; i < answers.length; i++) {
            arr[0][i] = pattern1[i % pattern1.length];
            arr[1][i] = pattern2[i % pattern2.length];
            arr[2][i] = pattern3[i % pattern3.length];
        }
        
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        
        for (int j = 0; j < answers.length; j++) {
            if (arr[0][j] == answers[j]) {
                cnt1++;
            }
            if (arr[1][j] == answers[j]) {
                cnt2++;
            }
            if (arr[2][j] == answers[j]) {
                cnt3++;
            }
        }
        int count = 0;
        int[] cnts = {cnt1, cnt2, cnt3};
        int max = Math.max(cnt1, Math.max(cnt2, cnt3));
        for (int k = 0; k < 3; k++) {
            if (cnts[k] == max) {
                count++;
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < cnts.length; i++) {
            if (cnts[i] == max) {
                res.add(i+1);
            }
        }
        Integer[] res1 = res.toArray(new Integer[count]);
        return res1;
        
        
        
    }
}
