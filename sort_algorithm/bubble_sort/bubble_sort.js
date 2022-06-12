const bubbleSort = (array) => {
  for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array.length - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        let temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
    }
  }
};

const testArray = [5, 8, 6, 4, 1, 2, 7, 8, 3];

console.log(testArray);
bubbleSort(testArray);
console.log(testArray);
