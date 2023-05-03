package sortingClean;
import jakarta.inject.Inject;

import java.util.Random;

public class AlgorithmRunner {
    //each class field has a unique annotation corresponding to the correct injection
    @Inject
    @QuadAlgo SortingAlgorithm<Integer> quadraticAlgorithm;

    @Inject
    @NLogNAlgo SortingAlgorithm<Integer> nlognAlgorithm;

    @Inject
    @RandAlgo SortingAlgorithm<Integer> randomAlgorithm1;

    @Inject
    @RandAlgo SortingAlgorithm<Integer> randomAlgorithm2;

    @Inject
    @ArraySize int numberOfElements;

    public void runAlgorithms(){
        Random rand = new Random();
        Integer[] ints = rand.ints(1,Integer.MAX_VALUE)
                .distinct()
                .limit(numberOfElements)
                .boxed()
                .toArray(Integer[]::new);
        Integer[] intsClone = ints.clone();
        quadraticAlgorithm.sort(intsClone);
        intsClone = ints.clone();
        nlognAlgorithm.sort(intsClone);
        intsClone = ints.clone();
        randomAlgorithm1.sort(intsClone);
        intsClone = ints.clone();
        randomAlgorithm2.sort(intsClone);
    }
}
