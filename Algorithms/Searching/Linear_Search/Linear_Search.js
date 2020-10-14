/*JavaScript Implementation of linear Search */

function linearSearch(arr, item) {
  // Go through all the elements of arr to look for item.
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] === item) { // Found it!
      console.log( "Element" + item + " found at index " + i) ;
      return ;
    }
  }
  
  // Item not found in the array.
  console.log("Element" + item + " is not present in the given array");
}

function main(){
    var arr = [5,10,15,20,25];
    var item = 20;
    linearSearch(arr,item);
}

main();