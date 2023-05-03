import java.util.Random;

public class Nimbus1TemperatureSensor extends Sensor {

	private Random random;

	public Nimbus1TemperatureSensor(String type, int interval) {
		super(type, interval);
		random = RandomSupplier.getRnd();
	}

	@Override
	protected int read() {
		return random.nextInt(40);  // [0, 39]
	}

	@Override
	public String getTypeName() {
		return "temperature";
	}
}
