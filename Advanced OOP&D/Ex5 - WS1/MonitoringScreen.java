public class MonitoringScreen {
    public MonitoringScreen(WeatherMonitoringSystem ws) {
        System.out.println("MonitoringScreen was created");
        ws.addTemperatureObserver(new MSTempObserver(this));
        ws.addPressureObserver(new MSPressObserver(this));
    }

    public void displayTemperature(Integer data) {
        System.out.println("MonitoringScreen: temperature = " + data + " Celsius");
    }

    public void displayPressure(Integer data) {
        System.out.println("MonitoringScreen: pressure = " + data + " millibars");
    }
}