package dxc.add.controller;

import dxc.add.api.CategoryApi;
import dxc.add.constants.WebContstants;
import dxc.add.model.Category;
import dxc.add.model.PerformCategory;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(WebContstants.REST_CONTEX_STRING + "/v1/")
public class CategoryController implements CategoryApi {

    @Override
    public ResponseEntity<List<Category>> getAllCategories() {
        return CategoryApi.super.getAllCategories();
    }

    @Override
    public ResponseEntity<Category> getCategoryById(Integer id) {
        return CategoryApi.super.getCategoryById(id);
    }

    @Override
    public ResponseEntity<Category> createCategory(PerformCategory body) {
        return CategoryApi.super.createCategory(body);
    }

    @Override
    public ResponseEntity<Category> updateCategoryById(Integer id, PerformCategory body) {
        return CategoryApi.super.updateCategoryById(id, body);
    }

    @Override
    public ResponseEntity<Void> deleteCategoryById(Integer id) {
        return CategoryApi.super.deleteCategoryById(id);
    }

}
