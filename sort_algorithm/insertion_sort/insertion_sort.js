const inserstionSort = (arr) => {
  let item, j;

  for (let i = 1; i < arr.length; i++) {
    item = arr[i];

    j = i - 1;

    while (j >= 0 && arr[j] > item) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = item;
  }
};

const testArray = [2, 4, 6, 9, 8, 3, 6];

console.log(testArray);

inserstionSort(testArray);

console.log(testArray);
