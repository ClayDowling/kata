/**
 * Created by cdowling on 3/17/17.
 */
public class WeatherChannel implements IObserver {

    public int temperature;
    private String city;

    public WeatherChannel(String city) {
        this.city = city;
    }

    @Override
    public void update(IWeatherStation subject) {

        WeatherData data = subject.getData(this.city);
        if(data != null) {
            this.temperature = data.temperature;
        }

    }
}
