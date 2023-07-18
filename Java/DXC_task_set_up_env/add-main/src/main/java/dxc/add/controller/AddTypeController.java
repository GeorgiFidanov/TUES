package dxc.add.controller;

import dxc.add.api.AddTypeApi;
import dxc.add.constants.WebContstants;
import dxc.add.model.AddType;
import dxc.add.model.PerformAddType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(WebContstants.REST_CONTEX_STRING + "/v1/")
public class AddTypeController implements AddTypeApi {

    @Override
    public ResponseEntity<AddType> getAddTypeById(Integer id) {
        return AddTypeApi.super.getAddTypeById(id);
    }

    @Override
    public ResponseEntity<List<AddType>> getAllAddTypes() {
        return AddTypeApi.super.getAllAddTypes();
    }

    @Override
    public ResponseEntity<AddType> createAddType(PerformAddType body) {
        return AddTypeApi.super.createAddType(body);
    }

    @Override
    public ResponseEntity<AddType> updateAddTypeById(Integer id, PerformAddType body) {
        return AddTypeApi.super.updateAddTypeById(id, body);
    }

    @Override
    public ResponseEntity<Void> deleteAddTypeById(Integer id) {
        return AddTypeApi.super.deleteAddTypeById(id);
    }

}
