class Solution {
    class MinHeap { //최소힙 클래스 선언
        private int[] heap; // 힙 선언
        private int size; // 크기 선언
        
        public MinHeap(int maxSize) {
            heap = new int[maxSize + 1]; // 
            size = 0;
        }
        
        private int parent(int pos) { return pos / 2; } // 부모 노드
        private int leftChild(int pos) { return 2 * pos; } // 왼쪽 자식 노드
        private int rightChild(int pos) { return (2 * pos) + 1; } // 오른쪽 자식 노드
        
        private void swap(int pos1, int pos2) {
            int temp = heap[pos1];
            heap[pos1] = heap[pos2];
            heap[pos2] = temp;
        } //swap 메서드 (새로운 값이 추가될 때 트리가 힙이 되도록 자식노드와 부모노드를 바꾸기 위함)
        
        public void insert(int element) {
            heap[++size] = element;
            int current = size;
            
            while (current > 1 && heap[current] < heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }
        
        public int remove() {
            if (size == 0) return -1;
            
            int popped = heap[1];
            heap[1] = heap[size--];
            
            int pos = 1;
            while (true) {
                int smallest = pos;
                int left = leftChild(pos);
                int right = rightChild(pos);
                
                if (left <= size && heap[left] < heap[smallest])
                    smallest = left;
                if (right <= size && heap[right] < heap[smallest])
                    smallest = right;
                
                if (smallest == pos) break;
                
                swap(pos, smallest);
                pos = smallest;
            }
            
            return popped;
        }
        
        public int peek() {
            if (size == 0) return -1;
            return heap[1];
        }
        
        public int getSize() {
            return size;
        }
    }
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        // 최소 힙 생성
        MinHeap minHeap = new MinHeap(scoville.length);
        
        // 모든 스코빌 지수를 힙에 삽입
        for (int s : scoville) {
            minHeap.insert(s);
        }
        
        // 가장 맵지 않은 음식의 스코빌 지수가 K보다 작고, 힙에 원소가 2개 이상 있을 때 계속 반복
        while (minHeap.peek() < K && minHeap.getSize() >= 2) {
            int first = minHeap.remove();
            int second = minHeap.remove();
            
            int newScoville = first + (second * 2);
            minHeap.insert(newScoville);
            
            answer++;
        }
        
        // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
        if (minHeap.peek() < K) {
            return -1;
        }
        
        return answer;
    }
}