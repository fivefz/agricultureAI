package com.sun.analyticplatform;

import com.sun.analyticplatform.model.DAO.MessageRepository;
import com.sun.analyticplatform.model.entity.Message;
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
    @Test
    public void test() throws Exception {
        //messageRepository.save(new Message());
    }

}
