const inversionCount = (inputArray) => {
  let invCount = 0;
  for (let i = 0; i < inputArray.length; i++) {
    for (let j = i; j < inputArray.length; j++) {
      if (inputArray[i] > inputArray[j]) {
        invCount++;
      }
    }
  }
  return invCount;
}
