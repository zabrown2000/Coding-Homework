public class LogPressTrendObserver implements Observer<Trend> {
    private Log log;

    public LogPressTrendObserver(Log log) {
        System.out.println("LogPressTrendObserver was created");
        this.log = log;
    }

    @Override
    public void update(Trend data) {
        log.displayPressureTrend(data);
    }
}