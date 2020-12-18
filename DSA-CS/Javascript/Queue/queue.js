class Node {
	constructor(data, next=null) {
		this.data = data;
		this.next = null;
	}
}


class Queue {
	constructor() {
		this.size = 0;
		this.head = null;
		this.tail = null;
	}

	enqueue(data) {
		const node = new Node(data);
		if (this.size === 0) {
			this.head = node;
			this.tail = node;
			return ++this.size;
		}
		this.tail.next = node;
		this.tail = node;
		return ++this.size;
	}

	dequeue() {
		if (this.size === 0) {
			return null;
		} else if (this.size === 1) {
			this.head = null;
			this.tail = null;
			return --this.size;
		}
		const temp = this.head;
		this.head = temp.next;
		temp.next = null;
		return --this.size;
	}
}

