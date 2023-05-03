package sortingClean;

import jakarta.enterprise.inject.Produces;
import org.jboss.weld.environment.se.Weld;
import org.jboss.weld.environment.se.WeldContainer;

import java.util.Random;

public class MainApp {
    static Weld weld = new Weld();
    static WeldContainer container = weld.initialize(); //used to initialize objects with dependency injection

    public static void main(String[] args) {
        AlgorithmRunner algorithmRunner = container.select(AlgorithmRunner.class).get();

        algorithmRunner.runAlgorithms();
    }

    private static SortingAlgorithm<Integer> makeRandomSortingAlgorithm(){
        Random random = new Random(System.currentTimeMillis());
        SortingAlgorithm<Integer> sortAlg= null;
        switch (random.nextInt(4)){
            case 0: sortAlg = container.select(QuickSort.class).get();
                break;
            case 1: sortAlg = container.select(MergeSort.class).get();
                break;
            case 2: sortAlg = container.select(BubbleSort.class).get();
                break;
            case 3: sortAlg = container.select(InsertionSort.class).get();
        }
        return sortAlg;
    }

    //producer for quadratic algorithm
    @Produces
    public @QuadAlgo SortingAlgorithm<Integer> quadSortingAlgoGenerator(){
        return container.select(BubbleSort.class).get();
    }

    //producer for nlogn algorithm
    @Produces
    public @NLogNAlgo SortingAlgorithm<Integer> nLogNAlgoGenerator(){
        return container.select(QuickSort.class).get();
    }

    //producer for a randomly chosen algorithm
    @Produces
    public @RandAlgo SortingAlgorithm<Integer> randAlgoGenerator(){
        return makeRandomSortingAlgorithm();
    }

    //producer for array size
    @Produces
    public @ArraySize int arraySizeGenerator(){
        return 10000;
    }
}
