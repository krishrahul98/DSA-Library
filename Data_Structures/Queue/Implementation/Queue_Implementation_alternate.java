import java.util.Arrays;

/**
 * An example demonstrating a queue in Java.
 *
 * @author BraveeSnow
 */
public class Queue_Implementation {
    /**
     * An implementation of a queue in Java.
     * @param <T> The parameter type for the queue.
     */
    public static class Queue<T> {
        /**
         * The object array containing queued data.
         */
        private Object[] data;

        /**
         * The 1-based size of the data array.
         */
        private int size;

        /**
         * Initialize an empty queue for type {@code T}.
         */
        public Queue() {
            data = new Object[]{};
            size = 0;
        }

        /**
         * Initialize a queue with an existing array of type {@code T}.
         *
         * @param array The existing array to queue.
         */
        public Queue(T[] array) {
            data = array;
            size = array.length;
        }

        /**
         * Add a new element to the end of the queue.
         *
         * @param elem The new element to be queued.
         */
        public void queue(T elem) {
            ++size;
            Object[] newList = new Object[size];
            System.arraycopy(data, 0, newList, 0, data.length);
            newList[size - 1] = elem;
            data = newList;
        }

        /**
         * Queue a list of type {@code T}.
         * @param elemList The elements to queue.
         */
        public void queue(T[] elemList) {
            size += elemList.length;
            Object[] newList = new Object[size];
            System.arraycopy(data, 0, newList, 0, data.length);
            System.arraycopy(elemList, 0, newList, data.length, elemList.length);
            data = newList;
        }

        /**
         * Removes the front element from the queue.
         */
        public void dequeue() {
            if (size == 0) return;
            data = Arrays.copyOfRange(data, 1, size);
            --size;
        }

        /**
         * Get the first element in the queue.
         *
         * @return The first element in the queue.
         */
        public Object front() {
            if (size == 0) return null;
            return data[0];
        }

        /**
         * Get the last element in the queue.
         *
         * @return The last element in the queue.
         */
        public Object rear() {
            if (size == 0) return null;
            return data[size - 1];
        }

        /**
         * Get the element at a specific index.
         *
         * @param index The index of the queue.
         * @return The element of the given index.
         */
        public Object get(int index) {
            return data[index];
        }

        /**
         * Return the queue in a string format.
         *
         * @return The queue represented as a string.
         */
        @Override
        public String toString() {
            return Arrays.toString(data);
        }
    }

    public static void main(String[] args) {
        // A queue for strings
        // Initialize a queue
        String[] stringTest = {"this", "is", "a", "string"};
        Queue<String> stringQueue = new Queue<>(stringTest);

        // All elements in the queue
        System.out.println(stringQueue.toString());

        // Add an element to the rear of the queue
        stringQueue.queue("!");
        System.out.println(stringQueue.toString());

        // Remove the front element
        stringQueue.dequeue();
        System.out.println(stringQueue.toString());

        // Return a value from the front
        System.out.printf("\"%s\" is of %s (Front)\n", stringQueue.front(), stringQueue.front().getClass());

        // Do the same for the rear
        System.out.printf("\"%s\" is of %s (Rear)\n", stringQueue.rear(), stringQueue.rear().getClass());

        // Get an element at an index
        System.out.printf("\"%s\" is at index 2\n", stringQueue.get(2));

        // Integer queue
        Queue<Integer> intQueue = new Queue<>();
        intQueue.queue(1);
        intQueue.queue(2);
        intQueue.queue(new Integer[]{1, 2, 3});
        System.out.println(intQueue.toString());
    }
}
