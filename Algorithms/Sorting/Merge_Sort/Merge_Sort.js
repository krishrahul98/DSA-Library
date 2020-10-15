/*

Author: Shail Shah
Github: /shailshah76

*/

const arr = [1,5,2,7,8,9,4,3,10,6];

const Merge = function(left, right) {

    let sort_arr = [];

    while(left.length && right.length){
        if(left[0] < right[0])
            sort_arr.push(left.shift());
        else 
            sort_arr.push(right.shift());
    }

    while(left.length)
        sort_arr.push(left.shift());

    while(right.length)
        sort_arr.push(right.shift());

    return sort_arr;
}

const Merge_Sort = function(a) {
    if(a.length < 2){
        return a;
    } else{
        let mid = Math.floor(a.length / 2);

        let left = Merge_Sort(a.slice(0,mid));
        let right = Merge_Sort(a.slice(mid, a.length));

        return Merge(left, right);

    }
}

console.log("Unsorted Array is: " + arr);
console.log("Sorted Array is: " + Merge_Sort(arr));