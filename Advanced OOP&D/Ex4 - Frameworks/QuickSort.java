package sortingClean;

public class QuickSort implements SortingAlgorithm {
    int partition(Comparable arr[], int low, int high)
    {
        Comparable pivot = arr[high];
        int i = (low-1); // index of smaller element
        for (int j=low; j<high; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j].compareTo(pivot)<0)
            {
                i++;

                // swap arr[i] and arr[j]
                Comparable temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap arr[i+1] and arr[high] (or pivot)
        Comparable temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }


    /* The main function that implements QuickSort()
      arr[] --> Array to be sorted,
      low  --> Starting index,
      high  --> Ending index */
    void qsort(Comparable arr[], int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[pi] is
              now at right place */
            int pi = partition(arr, low, high);

            // Recursively sort elements before
            // partition and after partition
            qsort(arr, low, pi-1);
            qsort(arr, pi+1, high);
        }
    }
    public void sort(Comparable[] array) {
        qsort(array, 0, array.length-1);
    }
}
