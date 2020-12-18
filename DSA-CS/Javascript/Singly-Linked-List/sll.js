class Node {
	constructor(data, next=null) {
		this.data = data;
		this.next = next;
	}
}


class SinglyLinkedList {
	constructor() {
		this.head = null;
		this.size = 0;
	}

	unshift(data) {
		const node = new Node(data);
		node.next = this.head;
		this.head = node;
		return ++this.size;
	}

	shift() {
		if (this.size < 1) {
			return null;
		}
		const temp = this.head;
		this.head = temp.next;
		this.size--;
		temp.next = null;
		return temp.data;
	}

	print() {
		let i = 0;
		let temp = this.head;
		while(i < this.size) {
			console.log(temp.data);
			temp = temp.next;
			i++;
		}
	}

	push(data) {
		if (this.size === 0) {
			return this.unshift(data);
		}
		const temp = new Node(data);
		let current = this.head;
		let i = 0;
		while (i < this.size - 1) {
			current = current.next;
			i++;
		}
		current.next = temp;
		return ++this.size;
	}

	pop() {
		if (this.size === 0) {
			return null;
		} else if (this.size === 1) {
			const data = this.head.data;
			this.size = 0;
			this.head = null;
			return data;
		}
		let i = 0;
		let current = this.head;
		while (i < this.size - 1) {
			current = current.next;
			i++;
		}
		current.next = null;
		this.size--;
		return current.data;
	}

	at(idx) {
		if (idx >= this.size) {
			return null;
		}
		let i = 0;
		let current = this.head;
		while (i < idx) {
			current = current.next;
			i++;
		}
		return current.data;
	}

	insert(idx, data) {
		if (idx > this.size) {
			throw new Error("Out of Bounds");
		} 
		let i = 0;
		let prev, current = this.head;
		while (i < idx) {
			prev = current;
			current = current.next;
			i++;
		}
		const node = new Node(data);
		prev.next = node;
		node.next = current;
		return ++this.size;
	}

	removeAt(idx) {
		if (idx >= this.size) {
			return null;
		}
		let i = 0;
		let prev, current = this.head;
		while (i < idx) {
			prev = current;
			current = current.next;
			i++;
		}
		prev.next = current.next;
		current.next = null;
		this.size--;
		return current.data;
	}
}

