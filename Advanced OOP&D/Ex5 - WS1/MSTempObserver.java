public class MSTempObserver implements Observer<Integer> {

    private MonitoringScreen monitoringScreen;

    public MSTempObserver(MonitoringScreen ms) {
        System.out.println("MSTempObserver was created");
        this.monitoringScreen = ms;
    }

    @Override
    public void update(Integer data) {
        this.monitoringScreen.displayTemperature(data);
    }
}