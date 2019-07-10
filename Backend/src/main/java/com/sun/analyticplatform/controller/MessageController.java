package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.MessageRepository;
import com.sun.analyticplatform.model.entity.Message;
import com.sun.analyticplatform.model.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

public class MessageController {
    @Autowired
    MessageRepository messageRepository;

    @PostMapping("/sendmessage")
    public String sendMessage(@RequestBody User user){
        return "-1 0 1";//-1 对方不存在 0 失败 1成功
    }

    @GetMapping("/inbox/{id}")
    public List<Message> getInbox(@RequestParam int id){
        return messageRepository.findAllByTo_IdAndReadedIsFalse();
    }

    @GetMapping("/outbox/{id}")
    public List<Message> getOutbox(@RequestParam int id){

    }

    @GetMapping("/message/{id}")
    public Message getMessage(@RequestParam int id){
        //return messageRepository;
    }

}
