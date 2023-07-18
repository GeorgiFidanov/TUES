package dxc.add.service.implementation;

import dxc.add.model.Location;
import dxc.add.model.PerformLocation;
import dxc.add.service.LocationServiceInterface;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class LocationService implements LocationServiceInterface {

    @Override
    public List<Location> getAll() {
        return null;
    }

    @Override
    public Location getOne(long id) {
        return null;
    }

    @Override
    public Location create(PerformLocation locationTO) {
        return null;
    }

    @Override
    public Location update(long id, PerformLocation locationTO) {
        return null;
    }

    @Override
    public void delete(long id) {

    }

}
