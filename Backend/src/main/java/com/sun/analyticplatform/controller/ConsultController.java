package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.ConsultRepository;
import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.Consult;
import com.sun.analyticplatform.model.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/consult")
public class ConsultController {

    @Autowired
    UserRepository userRepository;
    @Autowired
    ConsultRepository consultRepository;

    @GetMapping("/getexperts")
    public List<User> getExperts(){
        return userRepository.findAllByRole(User.Role.expert);
    }

    @GetMapping("/getadmins")
    public List<User> getAdmins(){
        return userRepository.findAllByRole(User.Role.admin);
    }

    @PostMapping("/consult")
    public String consult(@RequestBody Consult consult){
        consultRepository.save(consult);
        return "1";
    }

    @PostMapping("/reply")
    public String reply(@RequestBody Consult consult){
        Consult current = consultRepository.findById(consult.getId());
        current.setReply(consult.getReply());
        consultRepository.save(current);
        return "1";
    }

    @GetMapping("/getallfromme/{id}")
    public List<Consult> getAllFromMe(@PathVariable int id){
        return consultRepository.findAllByFromId(id);
    }

    @GetMapping("/getalltome/{id}")
    public List<Consult> getAllToMe(@PathVariable int id){
        return consultRepository.findAllByToId(id);
    }

    @GetMapping("/getInfo/{id}")
    public Consult getInfo(@PathVariable int consult_id){

        return consultRepository.findById(consult_id);
    }
}
