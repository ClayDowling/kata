import org.junit.Before;
import org.junit.Test;

import static org.hamcrest.Matchers.is;
import static org.junit.Assert.*;
import static org.mockito.AdditionalMatchers.not;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;

public class WeatherStationTest {

    WeatherStation station;

    WeatherChannel detroitWeather;
    WeatherChannel lansingWeather;

    @Before
    public void setUp() {
        this.station = new WeatherStation();
        this.detroitWeather = new WeatherChannel("Detroit");
        this.lansingWeather = new WeatherChannel("Lansing");
        this.station.registerObserver(this.detroitWeather);
        this.station.registerObserver(this.lansingWeather);
    }


    @Test
    public void addWeather_forDetroitWith25_detroitWeatherWillHaveTempOf25() {
        this.detroitWeather.temperature = -7;

        this.station.addWeather("Detroit", new WeatherData(25));

        assertThat(this.detroitWeather.temperature, is(25));
    }


    @Test
    public void shouldNotRegisterDuplicateObservers() {
        WeatherChannel mockChannel = mock(WeatherChannel.class);
        this.station.registerObserver(mockChannel);
        this.station.registerObserver(mockChannel);

        this.station.addWeather("Detroit", new WeatherData(25));

        verify(mockChannel, times(1)).update(this.station);
    }

    @Test
    public void addWeather_forDetroitWith22_andLansingWith14_detroitWeatherDifferentFromLansing() {
        this.detroitWeather.temperature = -7;
        this.lansingWeather.temperature = -7;

        this.station.addWeather("Detroit", new WeatherData(22));
        this.station.addWeather("Lansing", new WeatherData(14));

        assertThat(this.detroitWeather.temperature, is(22));
        assertThat(this.lansingWeather.temperature, is(14));

    }


    @Test
    public void addWeather_forDetroitWith22_andNotChangeLansing() {
        this.detroitWeather.temperature = -7;
        this.lansingWeather.temperature = -7;

        this.station.addWeather("Detroit", new WeatherData(87));

        assertThat(this.detroitWeather.temperature, is(87));
        assertThat(this.lansingWeather.temperature, is(-7));

    }

}