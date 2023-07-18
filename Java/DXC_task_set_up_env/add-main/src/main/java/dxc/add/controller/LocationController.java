package dxc.add.controller;

import dxc.add.api.LocationApi;
import dxc.add.constants.WebContstants;
import dxc.add.model.Location;
import dxc.add.model.PerformLocation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(WebContstants.REST_CONTEX_STRING + "/v1/")
public class LocationController implements LocationApi {

    @Override
    public ResponseEntity<List<Location>> getAllLocation() {
        return LocationApi.super.getAllLocation();
    }

    @Override
    public ResponseEntity<Location> getLocationById(Integer id) {
        return LocationApi.super.getLocationById(id);
    }

    @Override
    public ResponseEntity<Location> createLocation(PerformLocation body) {
        return LocationApi.super.createLocation(body);
    }

    @Override
    public ResponseEntity<Location> updateLocationById(Integer id, PerformLocation body) {
        return LocationApi.super.updateLocationById(id, body);
    }

    @Override
    public ResponseEntity<Void> deleteLocationById(Integer id) {
        return LocationApi.super.deleteLocationById(id);
    }

}
