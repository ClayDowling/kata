import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public abstract class IWeatherStation {

    boolean publishing;
    Set<IObserver> observers;

    protected IWeatherStation() {
        observers = new HashSet<IObserver>();
        publishing = false;
    }

    public void registerObserver(IObserver obs)
    {
        this.observers.add(obs);
    }

    protected void publish() {
        if (this.publishing) return;

        this.publishing = true;
        for(IObserver obs : this.observers) {
            obs.update(this);
        }

        this.publishing = false;
    }

    abstract WeatherData getData(String city);

}
