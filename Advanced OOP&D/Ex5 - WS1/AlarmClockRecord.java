public class AlarmClockRecord {
    private int interval;
    private AlarmListener listener;
    private int remaining;

    public AlarmClockRecord(int inter, AlarmListener al) {
        this.interval = inter;
        this.listener = al;
        this.remaining = inter;
    }

    public int getInterval() {
        return interval;
    }

    public int getRemainingTime() {
        return remaining;
    }

    public void setRemainingTime(int remaining) {
        this.remaining = remaining;
    }

    public AlarmListener getListener() {
        return listener;
    }

    public void decrementRemainingTime(int amount) {
        remaining -= amount;
    }

    public void resetRemainingTime() {
        remaining = interval;
    }
}