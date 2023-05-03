public class PressureTrendSensor extends Observable<Trend> implements Observer<Integer> {
    private Integer lastReading1 = null;
    private Integer lastReading2 = null;
    private Integer lastReading3 = null;

    private Trend lastState = Trend.STABLE;

    public PressureTrendSensor(Nimbus1PressureSensor pressSensor) {
        pressSensor.addObserver(this);
    }

    /**
     * Calculate the pressure trend.
     * This component returns “rising” if b<c && a<b, “falling” if b>c && a>b, and
     * "stable" in all other cases.
     * 
     * @return the pressure trend
     */
    public Trend calc() {
        if (lastReading1 == null || lastReading2 == null || lastReading3 == null) {
            return Trend.STABLE;
        }
        if (lastReading1 < lastReading2 && lastReading2 < lastReading3) {
            return Trend.FALLING;
        }
        if (lastReading1 > lastReading2 && lastReading2 > lastReading3) {
            return Trend.RISING;
        }
        return Trend.STABLE;
    }

    public void check() {
        Trend pressureState = calc();
        if (pressureState != lastState) {
            notifyObservers(pressureState);
            lastState = pressureState;
        }
    }

    @Override
    public void update(Integer data) {
        // Update the last three readings with the new data
        lastReading3 = lastReading2;
        lastReading2 = lastReading1;
        lastReading1 = data;
        // Check the trend and notify observers if the trend has changed
        check();
    }

    @Override
    public String getTypeName() {
        return "pressure trend";
    }
}
