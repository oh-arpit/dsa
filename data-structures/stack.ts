class MyNode<T> {
    val: T;
    next: MyNode<T>;

    constructor(val: T) {
        this.val = val;
        this.next = null;
    }
}

class MyStack<T> {
    private peek: MyNode<T>;
    private length: number;

    constructor() {
        this.peek = null;
        this.length = 0;
    }

    push(val: T): void {
        const newNode = new MyNode(val);
        newNode.next = this.peek;
        this.peek = newNode;
        ++this.length;
    }

    pop(): T {
        if(this.empty())
            return null;

        const val = this.peek.val;
        this.peek = this.peek.next;
        --this.length;
        return val;
    }

    top(): T {
        return this.empty() ? null : this.peek.val;
    }

    empty(): boolean {
        return this.peek === null;
    }

    size(): number {
        return this.length;
    }
}
