package com.sun.analyticplatform;

import com.sun.analyticplatform.model.DAO.MessageRepository;
import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.Message;
import com.sun.analyticplatform.model.entity.User;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.Date;

@RunWith(SpringRunner.class)
@SpringBootTest
public class MessageTest {
    @Autowired
    private MessageRepository messageRepository;
    @Autowired
    UserRepository userRepository;
    @Test
    public void test() throws Exception {
        User user1 = userRepository.findByUserName("user1");
        User user2 = userRepository.findByUserName("cc3");
        User admin = userRepository.findByUserName("admin");

        messageRepository.save(new Message(user1,user2,new Date(),"This is Test."));
        messageRepository.save(new Message(user1,admin,new Date(),"This is Test."));
        messageRepository.save(new Message(admin,user1,new Date(),"This is Test."));
        messageRepository.save(new Message(admin,user2,new Date(),"This is Test."));
    }

}
