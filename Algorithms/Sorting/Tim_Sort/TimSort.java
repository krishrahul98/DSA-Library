import java.lang.Math;
import java.util.Random;

class TimSort {
    int array[];
    int array_length;
    int RUN = 32;

    public TimSort(int[] array) {
        this.array = array;
        this.array_length = array.length;
    }

    public TimSort(int array_length) {
        Random rand = new Random();

        this.array_length = array_length;
        this.array = new int[this.array_length];

        for (int i = 0; i < this.array_length; i++) {
            int random_number = rand.nextInt(1000);
            this.array[i] = random_number;
        }
    }

    public void change_run(int run) {
        this.RUN = run;
    }

    public TimSort() {
        this.array_length = 100;
        this.array = new int[this.array_length];

        Random rand = new Random();
        for (int i = 0; i < this.array_length; i++) {
            int random_number = rand.nextInt(1000);
            this.array[i] = random_number;
        }
    }

    public void insertion_sort(int[] array, int start_idx, int end_idx) {
        for (int i = 0; i < array.length; i++) {
            int current_element = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > current_element) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = current_element;
        }
    }

    public void merge_runs(int array[], int start, int mid, int end) {

        int first_array_size = mid - start + 1, second_array_size = end - mid;
        int array1[] = new int[first_array_size], array2[] = new int[second_array_size];
        int i = 0, j = 0, k = 0;

        // Building the two sub arrays from the array to merge later
        for (i = 0; i < first_array_size; i++)
            array1[i] = array[start + i];
        for (i = 0; i < second_array_size; i++)
            array2[i] = array[mid + 1 + i];

        i = 0;
        j = 0;
        k = start;

        while (i < first_array_size && j < second_array_size) {
            if (array1[i] <= array2[j]) {
                array[k] = array1[i];
                i++;
            } else {
                array[k] = array2[j];
                j++;
            }
            k++;
        }

        while (i < first_array_size) {
            array[k] = array1[i];
            k++;
            i++;
        }

        while (j < second_array_size) {
            array[k] = array2[j];
            k++;
            j++;
        }
    }

    public void algorithm() {
        // Before Sorting
        System.out.println("Before sorting the array: ");
        this.showArrayElements();
        System.out.println();

        // Applying insertion sort on RUNS.
        for (int i = 0; i < this.array_length; i += this.RUN)
            this.insertion_sort(this.array, i, Math.min(i + this.RUN, (this.array_length - 1)));

        for (int split = this.RUN; split < this.array_length; split = 2 * split) {
            for (int start_idx = 0; start_idx < this.array_length; start_idx += 2 * split) {
                int mid = start_idx + split - 1;
                int end_idx = Math.min((start_idx + 2 * split - 1), (this.array_length - 1));

                this.merge_runs(this.array, start_idx, mid, end_idx);
            }
        }
        // After sorting
        System.out.println("After sorting the array: ");
        this.showArrayElements();
        System.out.println();
    }

    public void showArrayElements() {
        for (int i = 0; i < this.array.length; i++) {
            System.out.print(this.array[i] + " ");
        }
        System.out.println();
    }
}

class Main {
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
