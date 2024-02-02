class MyNode<T> {
    val: T;
    next: MyNode<T>;
    
    constructor(val: T) {
        this.val = val;
        this.next = null;
    }
}
    
class MyQueue<T> {
    private head: MyNode<T>;
    private tail: MyNode<T>;
    private length: number;
    
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    
    push(val: T): void {
        const newNode = new MyNode(val);
        
        if(this.empty()) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        
        ++this.length;
    }
    
    pop(): T {
        if(this.empty())
            return null;
    
        const val = this.head.val;
        this.head = this.head.next;
        if(this.empty()) this.tail = null;
    
        --this.length;
        return val;
    }
    
    front(): T {
        return this.empty() ? null : this.head.val;
    }
    
    empty(): boolean {
        return this.head === null;
    }
    
    size(): number {
        return this.length;
    }
}