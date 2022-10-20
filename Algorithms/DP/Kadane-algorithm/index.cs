var input = new int[] {1, -3, -7, 1, -2, 4, -1, 2, 1, -5, 4, 1, -5, -3, 1, 0};
var foundMaximum = kadane(input);

Console.WriteLine($"The solution for the maximum subarray problem \nfor the given array using Kadane's algorithm is: {foundMaximum}");

/// Kadane's algorithm solves the maximum subarray problem.
/// This is the task of finding the largest possible sum of a contiguous subarray within a array of numbers.
static int kadane(int[] numbers)
{
    if (numbers.Length == 0) return 0;
    var localMaximum = 0;
    var maximum = Int32.MinValue;

    for (var i = 0; i < numbers.Length; i++)
    {
        localMaximum = Math.Max(numbers[i], numbers[i] + localMaximum);
        if(localMaximum > maximum) maximum = localMaximum;
    }

    return maximum;
}