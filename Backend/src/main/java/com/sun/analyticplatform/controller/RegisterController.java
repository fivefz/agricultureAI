package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class RegisterController {

    @Autowired
    UserRepository userRepository;

    @PostMapping("/register")
    public  String register(@RequestBody User user){//username email phone 不能重复
        System.out.println(user.toString());
        if (userRepository.existsUserByUserName(user.getUserName())
        || userRepository.existsUserByEmail(user.getEmail())
        || userRepository.existsUserByPhone(user.getPhone())){
            return "-1";
        }
        User newer = userRepository.save(user);

        System.out.println("newer:"+newer.toString());
        return String.valueOf(newer.getId());


    }
}
