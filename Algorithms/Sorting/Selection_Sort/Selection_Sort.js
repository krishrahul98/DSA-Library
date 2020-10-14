/*

Author: Shail Shah
Github: /shailshah76

*/

const arr = [1,5,3,-7,4,9,10];


const getMin = function(a,l,r){
    let min = 0;
    for(let i=l;i<r;i++){
        if(a[min] > a[i])
            min = i;
    }
    return min;
}


const Selection_Sort = function(a){
    let len = a.length;

    for(let i=0;i<=len;i++){
        let min = getMin(arr,i,len);

        let temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

console.log("Unsorted Array is: " + arr);
Selection_Sort(arr);
console.log("Sorted Array is: " + arr);