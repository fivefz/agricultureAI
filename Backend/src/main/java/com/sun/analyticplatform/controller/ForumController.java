package com.sun.analyticplatform.controller;

import com.sun.analyticplatform.model.DAO.PosterRepository;
import com.sun.analyticplatform.model.DAO.ReplyRepository;
import com.sun.analyticplatform.model.entity.Poster;
import com.sun.analyticplatform.model.entity.Reply;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/forum")
public class ForumController {

    @Autowired
    PosterRepository posterRepository;
    @Autowired
    ReplyRepository replyRepository;

    @GetMapping("/getallposter")
    public List<Poster> getAllPoster(){
        return posterRepository.findAll();
    }

    @GetMapping("/getposterInfo")
    public Poster getPosterInfo(@RequestParam int id){
        return posterRepository.findById(id);
    }

    @PostMapping("/addposter")
    public String addPoster(@RequestBody Poster poster){
        posterRepository.save(poster);
        return "1";
    }

    @PostMapping("/addreply")
    public String addReply(@RequestBody Reply reply){
        replyRepository.save(reply);
        return  "1";
    }


}
