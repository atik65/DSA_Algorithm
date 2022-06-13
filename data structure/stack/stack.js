class Stack {
  constructor(top) {
    this.data = [];
    this.top = top;
  }

  push(item) {
    this.data[this.top] = item;
    this.top++;
  }

  pop() {
    if (this.top == 0) {
      return "Stack is Empty";
    } else {
      this.top--;
      const item = this.data[this.top];
      this.data[this.top] = null;
      return item;
    }
  }
}

let newStack = new Stack();
newStack.top = 0;
newStack.push(10);
newStack.push(20);
newStack.push(30);
newStack.push(40);
newStack.push(50);

newStack.pop();

newStack.data.map((item) => {
  console.log(item);
});
