package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.TUESkyException;
import org.elsys.tuesky.api.trips.Layover;

import java.time.Duration;
public class LayoverImpl implements Layover {
    private final Duration duration;

    public LayoverImpl(Duration duration) {

        if(duration == null) {
            throw new TUESkyException("Duration is null");
        }

        if(duration.isNegative() || duration.isZero()) {
            throw new TUESkyException("Invalid duration");
        }

        this.duration = duration;
    }

    @Override
    public Duration getDuration() {
        return duration;
    }
}
