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

    @GetMapping("/personalInfo/{id}")
    public User GetPersonalInfo(@PathVariable(value = "id")Integer id){
        User user = userRepository.findById(id);
        return user;
    }

    @PostMapping("/editpersonalInfo")
    @ResponseBody
    public void EditPersonalInfo(@RequestBody User user){
        //emial name password phone
        User updater = userRepository.findById(user.getId());
        updater.setUserName(user.getUserName());
        updater.setEmail(user.getEmail());
        updater.setPassword(user.getPassword());
        updater.setPhone(user.getPhone());
        userRepository.save(updater);
    }

    @PostMapping("/updatepassword")
    public String updatePassword(@RequestBody User user){
        User updater = userRepository.findById(user.getId());
        updater.setPassword(user.getPassword());
        userRepository.save(updater);
        return "1";
    }




}
