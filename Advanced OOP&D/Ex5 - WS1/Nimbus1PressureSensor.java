import java.util.Random;

public class Nimbus1PressureSensor extends Sensor {
	private Random random;

	public Nimbus1PressureSensor(String type, int interval) {
		super(type, interval);
		random = RandomSupplier.getRnd();
	}

	@Override
	protected int read() {
		return random.nextInt(100) + 950; // [950, 1049]
	}

	@Override
	public String getTypeName() {
		return "pressure";
	}
}
