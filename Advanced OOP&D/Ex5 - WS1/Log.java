public class Log {
    public Log(WeatherMonitoringSystem ws) {
        System.out.println("Log was created");
        ws.addPressureObserver(new LogPressObserver(this));
        ws.addPressureTrendObserver(new LogPressTrendObserver(this));
    }

    public void displayPressure(Integer data) {
        System.out.println("Log: pressure = " + data + " millibars");
    }

    public void displayPressureTrend(Trend data) {
        System.out.println("Log: pressure trend = " + data.toString());
    }
}