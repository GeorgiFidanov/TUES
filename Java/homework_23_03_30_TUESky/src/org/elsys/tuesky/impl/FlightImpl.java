package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.*;

import java.time.Duration;

public class FlightImpl implements Flight {
    private final String origin;
    private final String destination;
    private final Duration duration;

    public FlightImpl(String origin, String destination, Duration duration) {
        this.origin = origin;
        this.destination = destination;
        this.duration= duration;
    }

    @Override
    public String getOrigin() {
        return origin;
    }

    @Override
    public String getDestination() {
        return destination;
    }

    @Override
    public Duration getDuration() {
        return duration;
    }
}
