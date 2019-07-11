package com.sun.analyticplatform.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.io.*;

@Controller
public class AvatarController {
    //头像上传位置
    private String avatarDir = "H:\\advanced\\agricultureAI\\Backend\\src\\main\\resources\\avatar\\";
//重写 没有返回默认 有返回对应头像

    @GetMapping("/avatar/downloadAvatar/{id}")
    @ResponseBody
    public void downloadAvatar(@PathVariable("id") String id, HttpServletResponse response) {

        byte[] buffer = new byte[1024];
        FileInputStream fis = null;
        BufferedInputStream bis = null;

        String avatarURL = avatarDir+id+".jpg";
        File avatar = new File(avatarURL);

        if (!avatar.exists()){
            avatarURL = avatarDir + "default.jpg";
            avatar = new File(avatarURL);
        }
        try {
            fis = new FileInputStream(avatar);
            bis = new BufferedInputStream(fis);
            OutputStream os = response.getOutputStream();
            int i = bis.read(buffer);
            while (i != -1) {
                os.write(buffer, 0, i);
                i = bis.read(buffer);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (bis != null) {
                try {
                    bis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    @PostMapping(value = "/avatar/uploadAvatar/{id}")
    @ResponseBody
    public String upload(@RequestParam("file") MultipartFile file,
                         @PathVariable("id") String id) {
        String filePath = avatarDir;
        File dest = new File(filePath + id+".jpg");
        try {
            file.transferTo(dest);
            return "1";
        } catch (IOException e) {
        }
        return "0";
    }


}
