package dxc.add.service.implementation;

import dxc.add.model.AddType;
import dxc.add.model.PerformAddType;
import dxc.add.service.AddTypeServiceInterface;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class AddTypeService implements AddTypeServiceInterface {

    @Override
    public List<AddType> getAll() {
        return null;
    }

    @Override
    public AddType getOne(long id) {
        return null;
    }

    @Override
    public AddType create(PerformAddType addTypeDto) {
        return null;
    }

    @Override
    public AddType update(long id, PerformAddType addTypeDto) {
        return null;
    }

    @Override
    public void delete(long id) {

    }

}
