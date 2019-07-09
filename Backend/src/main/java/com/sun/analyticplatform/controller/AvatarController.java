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

    @GetMapping("/avatar/downloadAvatar")
    @ResponseBody
    public String downloadAvatar(@RequestParam("id") String id, HttpServletResponse response) {
        String avatarURL = avatarDir+id+".jpg";
        File avatar = new File(avatarURL);
        if (avatar.exists()) {
            byte[] buffer = new byte[1024];
            FileInputStream fis = null;
            BufferedInputStream bis = null;
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
                return "download success";
            }
        }
        else return "file isn't exist";
    }

    @PostMapping(value = "/avatar/uploadAvatar")
    @ResponseBody
    public String upload(@RequestParam("file") MultipartFile file,
                         @RequestParam("id") String id) {
        if (file.isEmpty()) {
            return "上传失败，请选择文件";
        }

        String filePath = avatarDir;
        File dest = new File(filePath + id+".jpg");
        try {
            file.transferTo(dest);
            return "上传成功";
        } catch (IOException e) {
        }
        return "上传失败！";
    }


}
