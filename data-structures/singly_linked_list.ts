// https://leetcode.com/problems/design-linked-list/description/

class MyNode {
    val: number;
    next: MyNode;

    constructor(val: number) {
        this.val = val;
        this.next = null;
    }
}

class MyLinkedList {
    private head: MyNode;
    private tail: MyNode;
    private length: number;

    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    private getNode(index: number): MyNode {
        if(index < 0 || index >= this.length)
            return null;

        let itr = this.head;

        while(index > 0) {
            itr = itr.next;
            --index;
        }

        return itr;
    }

    get(index: number): number {
        return this.getNode(index)?.val ?? -1;
    }

    addAtHead(val: number): void {
        const newNode = new MyNode(val);
        newNode.next = this.head;
        this.head = newNode;
        if(!this.tail) this.tail = this.head;
        ++this.length;
    }

    addAtTail(val: number): void {
        const newNode = new MyNode(val);
        if(this.tail) this.tail.next = newNode;
        this.tail = newNode;
        if(!this.head) this.head = this.tail;
        ++this.length;
    }

    addAtIndex(index: number, val: number): void {
        if(index < 0 || index > this.length)
            return;

        const newNode = new MyNode(val);
        const prevNode = this.getNode(index - 1);

        if(!prevNode) {
            newNode.next = this.head;
            this.head = newNode;
        } else {
            newNode.next = prevNode.next;
            prevNode.next = newNode;
        }

        if(index === this.length)
            this.tail = newNode;

        ++this.length;
    }

    deleteAtIndex(index: number): void {
        if(index < 0 || index >= this.length)
            return;

        const prevNode = this.getNode(index - 1);

        if(!prevNode) {
            this.head = this.head.next;
            if(!this.head) this.tail = null;
        } else {
            prevNode.next = prevNode.next.next;
            if(!prevNode.next) this.tail = prevNode;
        }

        --this.length;
    }
}

type Node = ListNode | null;

function reverseList(head: Node): Node {
    if(!head) return head;

    let prevNode: Node = null;
    let curNode: Node = head;

    while(curNode !== null) {
        const nextNode = curNode.next;
        curNode.next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }

    return prevNode;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
