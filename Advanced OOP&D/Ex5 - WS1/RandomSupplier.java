import java.util.Random;

public class RandomSupplier {
    private static Random rnd = new Random(1);

    public static Random getRnd() {
        return rnd;
    }
}
