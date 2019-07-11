package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.User;
import com.sun.analyticplatform.service.MailService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.Random;

@RestController
public class CodeController {
    @Autowired
    MailService mailService;
    @Autowired
    UserRepository userRepository;

    @PostMapping("/getcode")
    public String getCode(@RequestBody User user){

        Random random = new Random();
        String code =  String.valueOf(random.nextInt(900000)+9999);

        if (String.valueOf(user.getId()).isEmpty()){
            mailService.sendSimpleMail(user.getEmail(),"Auth Code",code);
        }
        else if (user.getEmail().isEmpty()){
            User receiver = userRepository.findById(user.getId());
            mailService.sendSimpleMail(receiver.getEmail(),"Auth Code",code);
        }else{
            mailService.sendSimpleMail(user.getEmail(),"Auth Code",code);
        }
        return code;
    }
}
