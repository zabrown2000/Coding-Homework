package sortingClean;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

@Aspect
public class PrintRuntime {
    //variables to keep track of time
    private static long startTime;
    private static long totalTime = 0;
    private static long bubbleTime = 0;
    private static long insertionTime = 0;
    private static long mergeTime = 0;
    private static long quickTime = 0;

    //variables to keep track of how many times each function was called
    private static int bubbleCtr = 0;
    private static int mergeCtr = 0;
    private static int insertionCtr = 0;
    private static int quickCtr = 0;

    //pointcut for sort functions
    @Pointcut("execution(* *.*.sort(..))")
    private void selectSorters() {}

    //pointcut for overall sorting algorithm running
    @Pointcut("execution(* *.*.runAlgorithms(..))")
    private void selectRunner() {}

    //advice to get start time and update counters
    @Before("selectSorters()")
    public void beforeSort(JoinPoint jp) {
        //updating how many times a class was called
        String className = jp.getThis().getClass().getSimpleName();
        switch (className) {
            case "BubbleSort":
                bubbleCtr++;
                break;
            case "InsertionSort":
                insertionCtr++;
                break;
            case "MergeSort":
                mergeCtr++;
                break;
            case "QuickSort":
                quickCtr++;
                break;
        }
        startTime = System.currentTimeMillis();
    }

    //advice to get and update duration for each sort and overall total time
    @After("selectSorters()")
    public void afterSorters(JoinPoint jp) {
        //get timestamp and get dif from class var
        long endTime = System.currentTimeMillis();
        long duration = endTime - startTime; //using most recent start time
        totalTime += duration;

        String classSortName = jp.getThis().getClass().getSimpleName();
        switch (classSortName) {
            case "BubbleSort":
                bubbleTime += duration;
                break;
            case "InsertionSort":
                insertionTime += duration;
                break;
            case "MergeSort":
                mergeTime += duration;
                break;
            case "QuickSort":
                quickTime += duration;
                break;
        }
    }

    //advice to print final results after all sort algorithms were run
    @After("selectRunner()")
    public void afterRunner(JoinPoint jp) {
        System.out.println("Total time of running all sort functions was " + totalTime + " ms");
        System.out.println("In detail:");
        if (bubbleCtr > 0) {
            System.out.println("Function sort in BubbleSort ran " + bubbleCtr + " times and took in total " + bubbleTime + " ms");
        }
        if (insertionCtr > 0) {
            System.out.println("Function sort in InsertionSort ran " + insertionCtr + " times and took in total " + insertionTime + " ms");
        }
        if (mergeCtr > 0) {
            System.out.println("Function sort in MergeSort ran " + mergeCtr + " times and took in total " + mergeTime + " ms");
        }
        if (quickCtr > 0) {
            System.out.println("Function sort in QuickSort ran " + quickCtr + " times and took in total " + quickTime + " ms");
        }
    }
}
