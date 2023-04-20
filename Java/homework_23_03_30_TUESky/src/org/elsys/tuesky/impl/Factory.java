package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.*;
import org.elsys.tuesky.api.trips.*;

import java.time.Duration;
import java.util.List;

public class Factory {

    public static Layover createLayover(Duration duration) {
        return new LayoverImpl(duration);
    }

    public static Planner createPlanner(List<Trip> trips) {return new PlannerImpl(trips);}

    public static TripBuilder startTrip() {
        return new TripBuilderImpl();
    }

    public static Flight createFlight(String from, String to, Duration duration) {return new FlightImpl(from, to, duration);}

}
