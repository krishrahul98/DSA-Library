function permutations(str) {
  // edge case: return the original string if there is only only character
  if (str.length === 1) return str;

  const characters = str.split('');

  // function that swaps a and b values in array
  function swap(arr, a, b) {
    const temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
  }

  // recursion function to produce all combos
  function permutate(arr, a, b, result) {
    for (let i = a; i <= b; i++) {
      swap(arr, a, i);
      let combo = arr.join('');
      result.add(combo);
      permutate(arr, a + 1, b, result);
      swap(arr, a, i)
    }

    return Array.from(result);
  }

  /*
    This method results in duplicate permuatations.
    Set is used to cleanly handle duplicates
  */

  return permutate(characters, 0, characters.length - 1, new Set);
}