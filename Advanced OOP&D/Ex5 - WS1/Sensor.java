public abstract class Sensor extends Observable<Integer> {
    private Integer lastReading = null;

    protected Sensor(String type, Integer interval) {
        // register this sensor with the alarm clock to be checked every interval
        Nimbus1Clock.theInstance().register(interval, new SensorAlarmListener(this));
        System.out.println(type + " registered to clock");
    }

    protected abstract int read();

    public void check() {
        Integer reading = read();
        // update the last reading and notify observers if the reading has changed
        if (!reading.equals(lastReading)) {
            lastReading = reading;
            this.notifyObservers(reading);
        }
    }
}