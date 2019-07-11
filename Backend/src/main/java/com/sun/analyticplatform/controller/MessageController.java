package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.MessageRepository;
import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.Message;
import com.sun.analyticplatform.model.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
@RestController
public class MessageController {
    @Autowired
    MessageRepository messageRepository;
    @Autowired
    UserRepository userRepository;


    @PostMapping("/sendmessage")
    public String sendMessage(@RequestBody Message message){
        if(!userRepository.existsUserById(message.getTo().getId())){
            return "-1";
        }
        messageRepository.save(message);
        return "1";//-1 对方不存在 0 失败 1成功
    }

    @GetMapping("/inbox/{id}")
    public List<Message> getInbox(@PathVariable int id){
        return messageRepository.findAllByToId(id);
    }

    @GetMapping("/outbox/{id}")
    public List<Message> getOutbox(@PathVariable  int id){
        return messageRepository.findAllByFromId(id);
    }

    @GetMapping("/message/{id}")
    public Message getMessage(@PathVariable int id){
        return messageRepository.findById(id);
    }

}
