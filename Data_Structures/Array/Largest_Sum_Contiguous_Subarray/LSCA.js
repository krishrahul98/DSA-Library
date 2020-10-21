/*
  The following function will return 0 if:
    - the length of the input array is 0
    - the array is made entirely of (-) numbers
*/

function LSCA(array) {
  if (array.length === 0) return 0;

  let currentMax = maxResult = 0;
  
  for (let i = 0; i < array.length; i++) {
    // will restart current contiguous subarray when encountering (-) numbers
    currentMax = Math.max(0, currentMax + array[i]);
    // will make sure max subarray isn't overwritten by excessive (-) numbers
    maxResult = Math.max(currentMax, maxResult);
  }
  return maxResult;
}