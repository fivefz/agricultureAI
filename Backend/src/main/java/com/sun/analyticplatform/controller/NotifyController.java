package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.NotifyRepository;
import com.sun.analyticplatform.model.entity.Notify;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class NotifyController {

    @Autowired
    NotifyRepository notifyRepository;

    @GetMapping("/notify")
    public List<Notify> getNotify(){
        return notifyRepository.findAll();
    }

    @GetMapping("/notify/{id}")
    public Notify getNotifyByID(@PathVariable int id){
        return notifyRepository.findById(id);
    }
}
