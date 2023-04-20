package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.TUESkyException;
import org.elsys.tuesky.api.planner.*;
import org.elsys.tuesky.api.trips.*;

import java.util.ArrayList;
import java.util.List;

public class PlannerImpl implements Planner {
    private final List<Trip> trips;

    public PlannerImpl(List<Trip> trips) {
        this.trips = trips;
    }

    @Override
    public List<Trip> search(TripQuery query) {
        List<Trip> found = new ArrayList<>();
        for (Trip trip : trips) {
            if (query.matches(trip)) {
                found.add(trip);
            }
        }
        if(found.isEmpty()){
            throw new TUESkyException("No matching trips");
        }
        return found;
    }

    @Override
    public boolean anyMatch(TripQuery query) {
        for (Trip trip : trips) {
            if (query.matches(trip)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public int count(TripQuery query) {
        int count = 0;
        for (Trip trip : trips) {
            if (query.matches(trip)) {
                count++;
            }
        }
        return count;
    }
}
