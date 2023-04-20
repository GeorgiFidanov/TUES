package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.TUESkyException;
import org.elsys.tuesky.api.trips.*;

import java.time.Duration;
import java.util.ArrayList;
import java.util.List;

public class TripBuilderImpl implements TripBuilder {
    private List<Flight> flights = new ArrayList<>();

    private Duration duration = Duration.ZERO;
    private Duration layovers = Duration.ZERO;

    @Override
    public TripBuilder then(TripUnit nextUnit) {
        if(nextUnit == null) {
            throw new TUESkyException("Invalid unit");
        }

        if(nextUnit instanceof Flight) {
            if(!flights.isEmpty()) {
                Flight prevFlight = flights.get(flights.size() - 1);
                if(!prevFlight.getDestination().matches(((Flight) nextUnit).getOrigin())){
                    throw new TUESkyException("Invalid locations");
                }
            }

            Flight flight = (Flight) nextUnit;

            flights.add(flight);
        }

        if(nextUnit instanceof Layover) {
            layovers = layovers.plus(nextUnit.getDuration());
        }

        duration = duration.plus(nextUnit.getDuration());

        return this;
    }
    //public TripBuilder add(Flight flight) {flights.add(flight);return this;}

    @Override
    public Trip end() {
        if (flights.isEmpty()) {
            throw new TUESkyException("Trip must contain at least one flight");
        }

        return new TripImpl(flights, duration, layovers);
    }
}

