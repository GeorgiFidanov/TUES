package dxc.add.service.implementation;

import dxc.add.model.ChangePassword;
import dxc.add.model.CreateUser;
import dxc.add.model.UpdateUser;
import dxc.add.model.User;
import dxc.add.service.UserServiceInterface;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserService implements UserServiceInterface {

    @Override
    public List<User> getAll() {
        return null;
    }

    @Override
    public User getOne(long id) {
        return null;
    }

    @Override
    public User create(CreateUser userDTO) {
        return null;
    }

    @Override
    public User update(long id, UpdateUser userDTO) {
        return null;
    }

    @Override
    public User changePassword(long id, ChangePassword changePasswordDTO) {
        return null;
    }

    @Override
    public void delete(long id) {

    }

}
