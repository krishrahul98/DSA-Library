function radixSort(arr) {
   const maxNum = Math.max(...arr) * 10;
   let divisor = 10;
   while (divisor < maxNum) {
      
      let buckets = [...Array(10)].map(() => []);
      
      for (let num of arr) {
         buckets[Math.floor((num % divisor) / (divisor / 10))].push(num);
      }
      arr = [].concat.apply([], buckets);
      
      divisor =divisor*10;
   }
   return arr;
}
console.log(radixSort([2,89,4,68,59,14,75,95,45,23,19,12]))
