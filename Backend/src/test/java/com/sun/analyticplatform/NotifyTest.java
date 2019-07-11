package com.sun.analyticplatform;

import com.sun.analyticplatform.model.DAO.NotifyRepository;
import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.Notify;
import com.sun.analyticplatform.model.entity.User;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.Date;

@RunWith(SpringRunner.class)
@SpringBootTest
public class NotifyTest {
    @Autowired
    NotifyRepository notifyRepository;
    @Autowired
    UserRepository userRepository;

    @Test
    public  void test(){
        User admin = userRepository.findByUserName("admin");
        System.out.println(notifyRepository.findAll().toString());
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title1.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title2.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title3.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title4.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title5.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title6.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title7.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title8.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title9.","This is Test Content."));
        notifyRepository.save(new Notify(admin,new Date(),"This is Test Title10.","This is Test Content."));
    }
}
