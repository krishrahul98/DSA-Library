function rotate(nums, k) {
  if (nums.length < k) k = k % nums.length;

  let tail = nums.slice(nums.length - k);
  for (let i = nums.length - k - 1; i >= 0; i--) {
    nums[i + k] = nums[i];
  }

  for (let j = 0; j < tail.length; j++) {
    nums[j] = tail[j];
  }

  return nums;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// let nums = [-1, -100, 3, 99];
// let k = 2;
let nums = [1, 2, 100, 23, 45, 65, 259];
let k = 3;

console.log(rotate(nums, k));
// Output -> [
//            45,  65, 259, 1,
//            2, 100,  23
//           ]
