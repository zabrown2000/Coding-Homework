import java.util.ArrayList;
import java.util.List;

public abstract class Observable<T> {
    private List<Observer<T>> observers = new ArrayList<>();

    public void addObserver(Observer<T> observer) {
        observers.add(observer);
        // print <object name> observes <sensor name>
        System.out.println(observer.getClass().getSimpleName() + " observes " + this.getTypeName());
    }

    public void notifyObservers(T data) {
        for (Observer<T> observer : observers) {
            observer.update(data);
        }
    }

    public abstract String getTypeName();
}