public class WeatherMonitoringSystem {
    private static WeatherMonitoringSystem instance = null;

    private Nimbus1TemperatureSensor tempSensor;
    private Nimbus1PressureSensor pressSensor;
    private PressureTrendSensor pressTrendSensor;

    protected WeatherMonitoringSystem() {
        System.out.println("WeatherMonitoringSystem was created");
        pressSensor = new Nimbus1PressureSensor("pressure", 1100);
        tempSensor = new Nimbus1TemperatureSensor("temperature", 700);
        pressTrendSensor = new PressureTrendSensor(pressSensor);
    }

    public static WeatherMonitoringSystem theInstance() {
        if (instance == null)
            instance = new WeatherMonitoringSystem();
        return instance;
    }

    public void addTemperatureObserver(Observer<Integer> o) {
        tempSensor.addObserver(o);
    }

    public void addPressureObserver(Observer<Integer> o) {
        pressSensor.addObserver(o);
    }

    public void addPressureTrendObserver(Observer<Trend> o) {
        pressTrendSensor.addObserver(o);
    }
}