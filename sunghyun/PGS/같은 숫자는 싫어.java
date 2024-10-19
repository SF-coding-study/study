import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Stack<Integer> st = new Stack<>();

        for (int i : arr) {
            if (st.isEmpty() || st.peek() != i ){
                st.push(i);
            }
        }

        int[] ans = new int[st.size()];
        
        for (int j = st.size() - 1; j >= 0; j--) {
            ans[j] = st.pop();
        }
        
        return ans;
    }
}