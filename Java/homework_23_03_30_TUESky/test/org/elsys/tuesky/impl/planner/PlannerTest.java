package org.elsys.tuesky.impl.planner;

import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.trips.Flight;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.impl.FlightImpl;
import org.elsys.tuesky.impl.PlannerImpl;
import org.elsys.tuesky.impl.TripImpl;
import org.junit.jupiter.api.Test;

import java.time.Duration;
import java.util.ArrayList;
import java.util.List;

public class PlannerTest {
    @Test
    void testGetTrips() {
        // Create some flights
        Flight flight1 = new FlightImpl("SOF", "LHR", Duration.ofHours(10));
        Flight flight2 = new FlightImpl("LHR", "JFK", Duration.ofHours(9));
        Flight flight3 = new FlightImpl("JFK", "LHR", Duration.ofHours(8));
        Flight flight4 = new FlightImpl("LHR", "SOF", Duration.ofHours(7));

        List<Flight> Bundle = new ArrayList<>();
        Bundle.add(flight1);
        Bundle.add(flight2);
        Bundle.add(flight3);
        Bundle.add(flight4);

        Trip trip1 = new TripImpl(Bundle,  Duration.ofHours(9),  Duration.ofHours(2));
        Trip trip2 = new TripImpl(Bundle,  Duration.ofHours(3),  Duration.ofHours(9));


        List<Trip> trips = new ArrayList<>();
        trips.add(trip1);
        trips.add(trip2);
        Planner planner = new PlannerImpl(trips);

    }
}
