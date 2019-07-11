package com.sun.analyticplatform.controller;

import org.json.JSONException;
import org.json.JSONObject;

import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.util.LinkedMultiValueMap;
import org.springframework.util.MultiValueMap;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@RestController
@RequestMapping("/analyse")
public class AnalyseController {

    String analyIP = "192.168.0.110";

    String farmerAnaly="http://"+analyIP+":8000/";

    String officerAnaly="http://"+analyIP+":9000/";

    String serverip = "http://192.168.0.109:80";


    @GetMapping("/farmer")
    public String farmerAnaly(@RequestParam int id,
                              @RequestParam String filename) throws JSONException, UnsupportedEncodingException {

        //return string id
        //id
        // image_url   ip:80/file/name
        String image_url = serverip+"/file/"+filename;
        RestTemplate restTemplate=new RestTemplate();

        HttpHeaders headers = new HttpHeaders();

        MultiValueMap<String, String> request = new LinkedMultiValueMap<>();
        request.add("id", String.valueOf(id));
        request.add("image_url", image_url);

        String msg = restTemplate.postForObject(farmerAnaly,  request, String.class);

        return AnalyseController.unicodeToString(msg);

    }

    @GetMapping("/officer")
    public void officerAnaly(@RequestParam int id,
                               @RequestParam String filename) throws JSONException {
        // image_url   ip:80/file/name
        //id
        // return_url ip:80/analyse/addresult/
        String image_url = serverip+"/file/"+filename;
        String return_url = serverip+"/analyse/addresult/"+id;
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        RestTemplate restTemplate=new RestTemplate();

        MultiValueMap<String, String> request = new LinkedMultiValueMap<>();
        request.add("id", String.valueOf(id));
        request.add("image_url", image_url);
        request.add("return_url",return_url);
        HttpEntity<MultiValueMap<String, String>> requestEntity  = new HttpEntity<MultiValueMap<String, String>>(request, headers);

        String msg = restTemplate.postForObject(officerAnaly,  request, String.class);

    }

    @PostMapping("/addresult/{id}")
    public String addResult(@RequestParam("file") MultipartFile file, @PathVariable int id){
        try {
            if (file.isEmpty()) {
                return "文件为空";
            }
            // 获取文件名
            String fileName = file.getOriginalFilename();
            // 获取文件的后缀名
            String suffixName = fileName.substring(fileName.lastIndexOf("."));
            // 设置文件存储路径
            String filePath = "H:\\advanced\\agricultureAI\\Backend\\src\\main\\resources\\files"+"\\"+id;
            String path = filePath + fileName;
            File dest = new File(path);
            // 检测是否存在目录
            if (!dest.getParentFile().exists()) {
                dest.getParentFile().mkdirs();// 新建文件夹
            }
            file.transferTo(dest);// 文件写入
            return "上传成功";
        } catch (IllegalStateException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "上传失败";
    }

    @GetMapping("/result/{id}")
    public String getResult(@PathVariable int id,
                            HttpServletRequest request,
                            HttpServletResponse response){
        String fileName = id+".png";// 文件名
        if (fileName != null) {
            //设置文件路径
            File file = new File("H:\\advanced\\agricultureAI\\Backend\\src\\main\\resources\\results" + fileName);
            if (file.exists()) {
                response.setContentType("application/force-download");// 设置强制下载不打开
                response.addHeader("Content-Disposition", "attachment;fileName=" + fileName);// 设置文件名
                byte[] buffer = new byte[1024];
                FileInputStream fis = null;
                BufferedInputStream bis = null;
                try {
                    fis = new FileInputStream(file);
                    bis = new BufferedInputStream(fis);
                    OutputStream os = response.getOutputStream();
                    int i = bis.read(buffer);
                    while (i != -1) {
                        os.write(buffer, 0, i);
                        i = bis.read(buffer);
                    }
                    return "1";
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
        }
        return "-1";
    }

    public static String unicodeToString(String str) {

        Pattern pattern = Pattern.compile("(\\\\u(\\p{XDigit}{4}))");
        Matcher matcher = pattern.matcher(str);
        char ch;
        while (matcher.find()) {
            //group 6728
            String group = matcher.group(2);
            //ch:'木' 26408
            ch = (char) Integer.parseInt(group, 16);
            //group1 \u6728
            String group1 = matcher.group(1);
            str = str.replace(group1, ch + "");
        }
        return str;
    }
}
