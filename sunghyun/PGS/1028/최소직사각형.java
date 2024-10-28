class Solution {
    public int solution(int[][] sizes) {
        int maxw = 0, maxh = 0, temp = 0;
        
        for (int i = 0; i < sizes.length; i++) {
            if (sizes[i][0] < sizes[i][1]) {
                temp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = temp;
            } // swap
            if (sizes[i][0] > maxw) {
                maxw = sizes[i][0];
            }
            if (sizes[i][1] > maxh) {
                maxh = sizes[i][1];
            }
        }
        return maxw * maxh;
    }
}