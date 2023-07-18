package dxc.add.service;

import dxc.add.model.Location;
import dxc.add.model.PerformLocation;

import java.util.List;

public interface LocationServiceInterface {

    List<Location> getAll();

    Location getOne(long id);

    Location create(PerformLocation locationTO);

    Location update(long id, PerformLocation locationTO);

    void delete(long id);

}
