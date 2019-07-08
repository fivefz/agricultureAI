package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.*;

@RestController
public class PersonalInfo {

    @Autowired
    private UserRepository userRepository;

    @GetMapping("/personalInfo{id}")
    public User GetPersonalInfo(@PathVariable(value = "id")Integer id){
        User user = userRepository.findById(id);
        return user;
    }

    @PostMapping("/editpersonalInfo{id}")
    @ResponseBody
    public void EditPersonalInfo(@RequestParam(required = true) String name,
                                    @RequestParam(required = true) String password,
                                    @RequestParam(required = true) String email,
                                    @RequestParam(required = true) String province,
                                    @RequestParam(required = true) String city){
        userRepository.save(new User(name,password,email,province,city));
    }




}
