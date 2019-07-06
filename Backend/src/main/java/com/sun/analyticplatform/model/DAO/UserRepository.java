package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends JpaRepository<User,Long> {
    User findByUserName(String userName);
    User findById(int id);
    User findByUserNameOrEmail(String username, String email);
}
