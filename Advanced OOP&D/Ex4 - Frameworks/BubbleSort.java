package sortingClean;

public class BubbleSort implements SortingAlgorithm {
    public void sort(Comparable[] array) {
        int n = array.length;
        Comparable temp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (n - i); j++) {
                if (array[j - 1].compareTo(array[j])>0) {
                    //swap elements
                    temp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = temp;
                }

            }
        }
    }
}
