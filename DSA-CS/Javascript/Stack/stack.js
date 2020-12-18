class Node {
	constructor(data, next=null) {
		this.data = data;
		this.next = next;
	}
}


class Stack {
	constructor() {
		this.head = null;
		this.size = 0;
	}

	push(data) {
		const node = new Node(data);
		node.next = this.head;
		this.head = node;
		return ++this.size;
	}

	pop() {
		if (this.size === 0) {
			return null;
		}
		const current = this.head;
		this.head = current.next;
		current.next = null;
		this.size--;
		return current.data;
	}

}

