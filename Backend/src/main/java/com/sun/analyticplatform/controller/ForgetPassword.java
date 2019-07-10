package com.sun.analyticplatform.controller;

import org.springframework.web.bind.annotation.PostMapping;

public class ForgetPassword {
    @PostMapping("/updatepassword")
    public String updatePassword(){
        return "1";
        //return "0";
    }
}
