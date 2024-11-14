import java.util.ArrayList;

class Solution {
    public int solution(int[] numbers, int target) {
        ArrayList<Integer> leaves = new ArrayList<>();
        leaves.add(0);  // 초기값 설정
        int count = 0;

        // 각 숫자를 순회하며 자손 노드를 계산
        for (int num : numbers) {
            ArrayList<Integer> temp = new ArrayList<>();
             
            for (int leaf : leaves) {
                temp.add(leaf + num);  // 더하는 경우
                temp.add(leaf - num);  // 빼는 경우
            }
            
            leaves = temp;
        }

        // 모든 경우의 수 중에서 target과 같은 값의 개수를 셈
        for (int leaf : leaves) {
            if (leaf == target) {
                count++;
            }
        }

        return count;
    }
}