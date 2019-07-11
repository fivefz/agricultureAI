package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ForgetPassword {

    @Autowired
    UserRepository userRepository;

    @PostMapping("/updatepassword")
    public String updatePassword(@RequestBody User user){


        return "1";
        //return "0";
    }
}
