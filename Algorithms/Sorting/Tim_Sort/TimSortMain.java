class TimSortMain {
    public static void main(String[] args) {

        // Demonstrating the three ways of invoking the algorithm.

        int array[] = { 130, 473, 267, 3, 540, 406, 994, 750, 569, 107, 501, 490, 781, 232, 245, 964, 458, 841, 826,
                110, 511, 994, 235, 27, 189, 112, 284, 832, 743, 903, 880, 379, 704, 159, 91, 782, 45, 810, 554, 32,
                886, 784, 415, 22, 255, 50, 232, 151, 436, 169, 771, 458, 950, 974, 342, 972, 534, 383, 148, 988 };

        TimSort obj = new TimSort(array);
        obj.algorithm();

        // Specifying the size of the array and let the constructor initialize a random
        // array.
        TimSort obj2 = new TimSort(50);
        obj2.algorithm();

        // Specifying nothing so that the constructor will initialize a random array
        TimSort obj3 = new TimSort();
        obj3.algorithm();

    }
}
