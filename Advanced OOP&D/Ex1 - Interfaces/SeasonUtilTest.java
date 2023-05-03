import java.util.Random;
import java.util.Scanner;

public class SeasonUtilTest {
    static final int TOTAL = 8;
    static final int ANIMAL_MIN_INITIAL_WEIGHT = 200;
    static final int ANIMAL_MAX_INITIAL_WEIGHT = 250;
    static final int TREE_MIN_INITIAL_HEIGHT = 150;
    static final int TREE_MAX_INITIAL_HEIGHT = 200;
    static final Season INITIAL_SEASON = Season.FALL;
    static Random random;

    public static void main(String[] args) {
        System.out.println("Enter Seed: ");
        Scanner scanner = new Scanner(System.in);
        random = new Random(scanner.nextInt());

        Animal[] animals=initializeAnimals();
        Tree[] trees =initializeTrees();

        System.out.println("\n---All animals---\n");
        System.out.println(SeasonUtil.reportAll(animals));
        System.out.println("\n---All trees---\n");
        System.out.println(SeasonUtil.reportAll(trees));

        System.out.println("\n---Sorting animals---\n");
        SeasonUtil.sortSeasonable(animals);
        System.out.println(SeasonUtil.reportAll(animals));

        System.out.println("\n---Sorting trees---\n");
        SeasonUtil.sortSeasonable(trees);
        System.out.println(SeasonUtil.reportAll(trees));
        

        Seasonable[] seasonables = new Seasonable[TOTAL*2] ;
        for (int i = 0; i < TOTAL; i++) {
            seasonables[2*i] = animals[i];
            seasonables[2*i+1] = trees[i];
        }
        
        System.out.println("\n---All together---\n");
        System.out.println(SeasonUtil.reportAll(seasonables));

        System.out.println("\n---change six seasons for animals and trees---\n");
        for (int i = 0; i<6; i++) {
            for (Seasonable seasonable:seasonables) {
                seasonable.changeSeason();
            }
            System.out.println("\n---All together after changing season---\n");
            System.out.println(SeasonUtil.reportAll(seasonables));
        }

        System.out.println("\n---Sorting animals after season change---\n");
        SeasonUtil.sortSeasonable(animals);
        System.out.println(SeasonUtil.reportAll(animals));

        System.out.println("\n---Sorting trees after season change---\n");
        SeasonUtil.sortSeasonable(trees);
        System.out.println(SeasonUtil.reportAll(trees));

    }
    private static Animal[] initializeAnimals() {
        Animal[] animals = new Animal[TOTAL];
        for (int i = 0; i < TOTAL; i++) {

            if(i<4)
                     animals[i] = new Caribou(ANIMAL_MIN_INITIAL_WEIGHT+ random.nextInt(ANIMAL_MAX_INITIAL_WEIGHT-ANIMAL_MIN_INITIAL_WEIGHT), INITIAL_SEASON);
            else
                animals[i] = new Bear(ANIMAL_MIN_INITIAL_WEIGHT+ random.nextInt(ANIMAL_MAX_INITIAL_WEIGHT-ANIMAL_MIN_INITIAL_WEIGHT), INITIAL_SEASON);
        }
        return animals;
    }
    private static Tree[] initializeTrees() {
        Tree[] trees = new Tree[TOTAL];
        for (int i = 0; i < TOTAL; i++) {

            if(i<4)
                trees[i] = new OliveTree(TREE_MIN_INITIAL_HEIGHT + random.nextInt(TREE_MAX_INITIAL_HEIGHT-TREE_MIN_INITIAL_HEIGHT), INITIAL_SEASON);
            else
                trees[i] = new FigTree(TREE_MIN_INITIAL_HEIGHT + random.nextInt(TREE_MAX_INITIAL_HEIGHT-TREE_MIN_INITIAL_HEIGHT), INITIAL_SEASON);
        }
        return trees;
    }
}
