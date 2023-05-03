import java.util.ArrayList;

public class AlarmClock {
    public final int CLOCK_INTERVAL_MILLIS = 100;
    protected static AlarmClock instance = null;
    private ArrayList<AlarmClockRecord> itsAlarmClockRecords = new ArrayList<>();

    protected AlarmClock() {
    }

    public static AlarmClock theInstance() {
        if (null == instance)
            instance = new AlarmClock();
        return instance;
    }

    protected void tic() {
        for (AlarmClockRecord alarmClockRecord : itsAlarmClockRecords) {
            // Reduce the remaining time by the clock interval
            alarmClockRecord.decrementRemainingTime(CLOCK_INTERVAL_MILLIS);
            // If the remaining time is less than or equal to zero, then
            // wake up the listener and reset the remaining time
            if (alarmClockRecord.getRemainingTime()-CLOCK_INTERVAL_MILLIS <= 0) {
                alarmClockRecord.getListener().wakeUp();
                alarmClockRecord.resetRemainingTime();
            }
            else {
                alarmClockRecord.setRemainingTime(alarmClockRecord.getRemainingTime()-CLOCK_INTERVAL_MILLIS);
            }
        }
    }

    public void register(int interval, AlarmListener alarmListener) {
        itsAlarmClockRecords.add(new AlarmClockRecord(interval, alarmListener));
    }
}
