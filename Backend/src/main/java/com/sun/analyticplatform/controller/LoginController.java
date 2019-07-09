package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

//密码要做加密处理
@RestController
public class LoginController {
    @Autowired
    private UserRepository userRepository;

    @PostMapping("/login")
    public String login(@RequestBody User user){
        System.out.println(user.toString());
        if(userRepository.findUserByIdAndPassword(user.getId(),user.getPassword()) != null){
            return "1";
        }else{
            return "0";
        }
    }
}
