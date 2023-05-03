public class MainClassWS1 {

    public static void main(String[] args) {
        // create sensors for observing
        WeatherMonitoringSystem ws = WeatherMonitoringSystem.theInstance();

        // register observers for each sensor
        new MonitoringScreen(ws);
        new Log(ws);
    }
}
