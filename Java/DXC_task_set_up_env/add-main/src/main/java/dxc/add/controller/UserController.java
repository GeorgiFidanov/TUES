package dxc.add.controller;

import dxc.add.api.UserApi;
import dxc.add.constants.WebContstants;
import dxc.add.model.ChangePassword;
import dxc.add.model.CreateUser;
import dxc.add.model.UpdateUser;
import dxc.add.model.User;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(WebContstants.REST_CONTEX_STRING + "/v1/")
public class UserController implements UserApi {


    @Override
    public ResponseEntity<List<User>> getAllUsers() {
        return UserApi.super.getAllUsers();
    }

    @Override
    public ResponseEntity<User> getUserById(Long id) {
        return UserApi.super.getUserById(id);
    }

    @Override
    public ResponseEntity<User> createUser(CreateUser body) {
        return UserApi.super.createUser(body);
    }

    @Override
    public ResponseEntity<User> updateUserById(Long id, UpdateUser body) {
        return UserApi.super.updateUserById(id, body);
    }

    @Override
    public ResponseEntity<User> changeUserPassword(Long id, ChangePassword body) {
        return UserApi.super.changeUserPassword(id, body);
    }

    @Override
    public ResponseEntity<Void> deleteUserById(Long id) {
        return UserApi.super.deleteUserById(id);
    }

}
