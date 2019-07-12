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
        //User admin
        //messageRepository.save(new Message());

    }

}
