package dxc.add.service;

import dxc.add.model.ChangePassword;
import dxc.add.model.CreateUser;
import dxc.add.model.UpdateUser;
import dxc.add.model.User;

import java.util.List;

public interface UserServiceInterface {

    List<User> getAll();

    User getOne(long id);

    User create(CreateUser userDTO);

    User update(long id, UpdateUser userDTO);

    User changePassword(long id, ChangePassword changePasswordDTO);

    void delete(long id);

}
