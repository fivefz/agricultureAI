package com.sun.analyticplatform;

import com.sun.analyticplatform.model.DAO.UserRepository;
import com.sun.analyticplatform.model.entity.User;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.test.context.junit4.SpringRunner;

import java.text.DateFormat;
import java.util.Date;

@RunWith(SpringRunner.class)
@SpringBootTest
public class UserTest {
    @Autowired
    private UserRepository userRepository;

    @Test
    public void test() throws Exception {

//        Date date = new Date();
//        DateFormat dateFormat = DateFormat.getDateTimeInstance(DateFormat.LONG, DateFormat.LONG);
//        String formattedDate = dateFormat.format(date);

        userRepository.save(new User("aa1","aa","aa@126.com","12345678910", "ShaanXi","Xi'an"));
        userRepository.save(new User("bb2","bb","bb@126.com","12345678911","ShaanXi","Xi'an"));
        userRepository.save(new User("cc3","cc","cc@126.com","12345678912","ShaanXi","Xi'an"));

        Assert.assertEquals("bb", userRepository.findByUserName("bb2").getPassword());
        userRepository.delete(userRepository.findByUserName("aa1"));
        System.out.println(userRepository.findAll().size());
    }

}
