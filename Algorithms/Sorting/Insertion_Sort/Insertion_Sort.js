/*

Author: Shail Shah
Github: /shailshah76

*/


const arr = [1,7,5,6,3,9,10,4]

const Insertion_Sort = function(a){
    let len = a.length;

    for(let i=0;i<len;i++){
       
        let temp = a[i];

        j = i-1;

        while(j>-1 && (temp < a[j])){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

console.log("Unsorted Array is: " + arr);
Insertion_Sort(arr);
console.log("Sorted Array is: " + arr);