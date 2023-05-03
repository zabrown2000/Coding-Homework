package sortingClean;

public class InsertionSort implements SortingAlgorithm {
    public void sort(Comparable[] array) {
        for (int i = 1; i<array.length; i++){
            Comparable key = array[i];
            int j = i-1;
            for (; j>-1 && array[j].compareTo(key)>0; j--){
                array[j+1]= array[j];
            }
            array[j+1]=key;
        }
    }
}
