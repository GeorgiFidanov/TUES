package dxc.add.service.implementation;

import dxc.add.model.Category;
import dxc.add.model.PerformCategory;
import dxc.add.service.CategoryServiceInterface;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CategoryService implements CategoryServiceInterface {

    @Override
    public List<Category> getAll() {
        return null;
    }

    @Override
    public Category getOne(long id) {
        return null;
    }

    @Override
    public Category create(PerformCategory categoryDTO) {
        return null;
    }

    @Override
    public Category update(long id, PerformCategory categoryDTO) {
        return null;
    }

    @Override
    public void delete(long id) {

    }

}
