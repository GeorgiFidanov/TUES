package dxc.add.service;

import dxc.add.model.Category;
import dxc.add.model.Location;
import dxc.add.model.PerformCategory;
import dxc.add.model.PerformLocation;

import java.util.List;

public interface CategoryServiceInterface {

    List<Category> getAll();

    Category getOne(long id);

    Category create(PerformCategory categoryDTO);

    Category update(long id, PerformCategory categoryDTO);

    void delete(long id);

}
