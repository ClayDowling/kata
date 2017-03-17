import java.util.HashMap;
import java.util.Map;


public class WeatherStation extends IWeatherStation {

    private Map<String, WeatherData> data;

    public WeatherStation() {
        data = new HashMap<String, WeatherData>();
    }

    public void addWeather(String city, WeatherData wd) {
        data.put(city, wd);
        this.publish();
    }

    @Override
    public WeatherData getData(String city) {
        return data.get(city);
    }

}
