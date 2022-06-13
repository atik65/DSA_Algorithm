const inserstionSort = (array) => {
  for (let i = 1; i < array.length; i++) {
    let item = array[i];

    let j = i - 1;

    while (j >= 0 && array[j] > item) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = item;
  }
};

const testArray = [2, 4, 6, 9, 8, 3, 6];

console.log(testArray);

inserstionSort(testArray);

console.log(testArray);
