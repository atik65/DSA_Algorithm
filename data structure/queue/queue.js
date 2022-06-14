class Queue {
  constructor(size) {
    this.QueueSize = size;
    this.head = 0;
    this.tail = 0;
    this.data = [this.QueueSize + 1];
  }

  Enqueue(item) {
    if ((this.tail + 1) % (this.QueueSize + 1) == this.head) {
      console.log("Queue is Full!!");
      return;
    }

    this.data[this.tail] = item;
    this.tail = (this.tail + 1) % (this.QueueSize + 1);
  }

  Dequeue() {
    if (this.head == this.tail) {
      console.log("Queue is Empty!!");
      return 0;
    }

    const item = this.data[this.head];
    this.head = (this.head + 1) % (this.QueueSize + 1);
    return item;
  }
}

const q1 = new Queue(5);
q1.Enqueue(10);
q1.Enqueue(20);
q1.Enqueue(30);
q1.Enqueue(40);
q1.Enqueue(50);
q1.Dequeue();
q1.Dequeue();
q1.Dequeue();
q1.Dequeue();
q1.Dequeue();

q1.Enqueue(50);
q1.Enqueue(50);
q1.Enqueue(50);
q1.Enqueue(50);
q1.Enqueue(50);

console.log(`head: ${q1.head} , tail: ${q1.tail}`);
