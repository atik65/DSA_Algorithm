const linearSearch = (array, x) => {
  for (let i = 0; i < array.length; i++) {
    if (array[i] == x) {
      return true;
    }
  }

  return false;
};

let testArray = [5, 7, 89, 14, -1, 4, -6, 524];
console.log(linearSearch(testArray, 256));
