const binarySearch = (array, x) => {
  let left = 0;
  let right = array.length - 1;

  while (left <= right) {
    let mid = Math.floor((left + right) / 2);

    if (array[mid] == x) {
      return true;
    }

    if (array[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
};

const testArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

console.log(binarySearch(testArray, 11));
