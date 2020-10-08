function swap(arr, first_Index, second_Index){
    var temp = arr[first_Index];
    arr[first_Index] = arr[second_Index];
    arr[second_Index] = temp;
}

function bubble_Sort(arr){
  var len = arr.length,
        i, j, stop;
    for (i=0; i < len; i++){
        for (j=0, stop=len-i; j < stop; j++){
            if (arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
    return arr;
}
console.log(bubble_Sort([10, 5, 2, 5, -6, 4, -1])); //array that is to be sorted

/*
algorithm
function swap( array, first_Element_index, second_element_index){
   swap the variables using temporary variable
}
function bubble_Sort(array)
{
len=array.length
 for i = 0 to len :
      swapped = false
		
      for j = 0 to len-i:
         (compare the adjacent elements)  
         if array[j] > array[j+1] then
            /* swap them */
            swap( array,j,j+1 )		 
            swapped = true
         end if
         
      end for
return arr
}    
pass the argument array
*/  