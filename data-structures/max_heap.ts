/* The heap is a tree data structure where each node is greater than or equal to its children (if it's a max heap)
   The binary heap is a complete binary tree that respects the heap property.

   Node: i
   Left Child: 2 * i + 1
   Right Child: 2 * i + 2
   Parent: (i - 1) / 2
 */

class PriorityQueue<T> {
    private heap: T[];

    constructor(nums: T[] = []) {
        this.heap = [];

        for(const num of nums)
            this.push(num);
    }

    push(val: T): void {
        let idx = this.size();
        let parentIdx = Math.floor((idx - 1) / 2);
        this.heap.push(val);

        while(idx > 0 && this.heap[idx] > this.heap[parentIdx]) {
            [this.heap[idx], this.heap[parentIdx]] = [this.heap[parentIdx], this.heap[idx]];
            idx = parentIdx;
            parentIdx = Math.floor((idx - 1) / 2);
        }
    }

    pop(): T {
        if(this.empty())
            return null;

        const val = this.heap[0];
        this.heap[0] = this.heap.at(-1);
        this.heap.pop();

        let idx = 0;
        let leftIdx = 2 * idx + 1;
        let rightIdx = 2 * idx + 2;

        while(leftIdx < this.size()) {
            let maxIdx = leftIdx;

            if(rightIdx < this.size() && this.heap[leftIdx] < this.heap[rightIdx])
                maxIdx = rightIdx;

            if(this.heap[maxIdx] <= this.heap[idx])
                break;

            [this.heap[idx], this.heap[maxIdx]] = [this.heap[maxIdx], this.heap[idx]];
            idx = maxIdx;
            leftIdx = 2 * idx + 1;
            rightIdx = 2 * idx + 2;
        }

        return val;
    }

    top(): T {
        return this.empty() ? null : this.heap[0];
    }

    size(): number {
        return this.heap.length;
    }

    empty(): boolean {
        return this.size() === 0;
    }
}
