using System;

class BinaryInsertionSort
{
    private static double binaryFindIndex(double[] array, int index)
    {
        double lowerIndex = 0;
        double middleIndex = 0;
        double upperIndex = index - 1;
        double nextValue = array[index];
        double nextValueIndex = -1;
        bool indexFound = false;

        if (index >= array.Length)
        {
            nextValueIndex = -1;
            indexFound = true;
        }

        while (upperIndex >= lowerIndex && !indexFound)
        {
            middleIndex = Math.Round((upperIndex + lowerIndex) / 2.0);
            if (upperIndex == lowerIndex || nextValue == array[(int)middleIndex])
            {
                if (nextValue > array[(int)middleIndex])
                {
                    nextValueIndex = middleIndex + 1;
                    indexFound = true;
                }
                else
                {
                    nextValueIndex = middleIndex;
                    indexFound = true;
                }
            }
            else if (nextValue < array[(int)middleIndex])
            {
                upperIndex = middleIndex - 1;
            }
            else if (nextValue > array[(int)middleIndex])
            {
                lowerIndex = middleIndex + 1;
            }
        }

        return indexFound ? nextValueIndex : lowerIndex;
    }

    private static double[] insertAtIndex(double[] array, double index, int elementIndex)
    {
        double elementToBeMoved = array[elementIndex];

        for (int i = elementIndex; i > index; i--)
        {
            array[i] = array[i - 1];
        }

        array[(int)index] = elementToBeMoved;

        return array;
    }
    public static double[] binaryInsertionSort(double[] array)
    {
        for (int index = 1; index < array.Length; index++)
        {
            double insertionIndex = binaryFindIndex(array, index);
            array = insertAtIndex(array, insertionIndex, index);
        }
        return array;
    }

    static void Main(string[] args)
    {
        double[] array = { 24, 5, 64, 5, 20, 88, 33, 84, 47, 81, 12, 91, 0 };
        double[] sortedArray = binaryInsertionSort(array);
        Console.WriteLine("[{0}]", string.Join(", ", sortedArray));
    }
}