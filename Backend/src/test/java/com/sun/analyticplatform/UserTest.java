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

        userRepository.save(new User("user1","pass","aa@126.com","12345678910", "ShaanXi","Xi'an"));
        userRepository.save(new User("user2","pass","bb@126.com","12345678911","ShaanXi","Xi'an"));
        userRepository.save(new User("user3","pass","cc@126.com","12345678912","ShaanXi","Xi'an"));
        userRepository.save(new User("expert1","pass","11@126.com","6666655589","ShaanXi","Xi'an", User.Role.expert));
        userRepository.save(new User("expert2","pass","22@126.com","6666655555","ShaanXi","Xi'an", User.Role.expert));
        userRepository.save(new User("officer1","pass","aa@126.com","12345678913", "ShaanXi","Xi'an", User.Role.officer));
        userRepository.save(new User("officer2","pass","bb@126.com","12345678914","ShaanXi","Xi'an", User.Role.officer));
        userRepository.save(new User("admin","pass","cc@126.com","12345678915","ShaanXi","Xi'an", User.Role.admin));

//        Assert.assertEquals("bb", userRepository.findByUserName("bb2").getPassword());
//        userRepository.delete(userRepository.findByUserName("aa1"));
//        System.out.println(userRepository.findAll().size());
    }

}
