package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.TUESkyException;
import org.elsys.tuesky.api.trips.*;

import java.time.Duration;

public class TripUnitImpl implements TripUnit {
    private final Duration duration;

    public TripUnitImpl(Duration duration) {
        if(duration == null || duration.isNegative() || duration.isZero()) {
            throw new TUESkyException("Duration of TripUnitImpl is empty");
        }
        this.duration = duration;
    }

    @Override
    public Duration getDuration() {
        return duration;
    }
}