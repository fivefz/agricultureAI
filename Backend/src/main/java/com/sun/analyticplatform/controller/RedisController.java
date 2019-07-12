package com.sun.analyticplatform.controller;

import java.util.Date;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("redis")
public class RedisController {
    @Autowired
    private StringRedisTemplate strRedis;

    @RequestMapping("/set")
    public String test() {
        strRedis.opsForValue().set("6", "56788");
        return "Redis complete";
    }


}
