package dxc.add.service;

import dxc.add.model.AddType;
import dxc.add.model.PerformAddType;

import java.util.List;

public interface AddTypeServiceInterface {

    List<AddType> getAll();

    AddType getOne(long id);

    AddType create(PerformAddType addTypeDto);

    AddType update(long id, PerformAddType addTypeDto);

    void delete(long id);

}
