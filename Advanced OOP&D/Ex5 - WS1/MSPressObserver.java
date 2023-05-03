public class MSPressObserver implements Observer<Integer> {

    private MonitoringScreen monitoringScreen;

    public MSPressObserver(MonitoringScreen ms) {
        System.out.println("MSPressObserver was created");
        this.monitoringScreen = ms;
    }

    @Override
    public void update(Integer data) {
        this.monitoringScreen.displayPressure(data);
    }
}