package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.*;
import org.elsys.tuesky.api.trips.*;

import java.time.Duration;
import java.util.List;

public  class TripImpl implements Trip {

    private final List<Flight> flights;
    private final Duration duration;
    private final Duration layovers;

    public TripImpl(List<Flight> flights, Duration duration, Duration layovers) {
        this.flights = flights;
        this.duration = duration;
        this.layovers = layovers;
    }

    @Override
    public String getOrigin() {
        return flights.get(0).getOrigin();
    }

    @Override
    public String getDestination() {
        return flights.get(flights.size() - 1).getDestination();
    }

    @Override
    public Duration getDuration() {
        return duration;
    }

    @Override
    public Duration getLayoverDuration() {
        return layovers;
    }

    @Override
    public int getFlightsCount() {
        return flights.size();
    }

    @Override
    public boolean matches(TripQuery query) {
        return query.matches(this);
    }
}
