package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends JpaRepository<User,Long> {
    User findByUserName(String userName);
    User findById(int id);
    void removeUserById(int id);
    @Query(value = "UPDATE USER SET user_name = ?2,password = ?3,email = ?4,province = ?5, city = ?6,role = ?7 WHERE id=?1 ",nativeQuery = true)
    void updateUserById(int id,String userName, String password, String email, String province, String city, User.Role role);
    @Query(value = "SELECT * FROM USER WHERE id=?1 AND password = ?2 ",nativeQuery = true)
    //User findUserByIdAndPassword(int id, String password);
    User findUserByIdAndPassword(int id,String password);
}
