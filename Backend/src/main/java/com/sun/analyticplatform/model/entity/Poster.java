package com.sun.analyticplatform.model.entity;

import org.springframework.format.annotation.DateTimeFormat;

import javax.persistence.*;
import java.util.Date;

@Entity
@Table(name = "poster")
public class Poster {
    private static final long serialVersionUID = 3L;
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(unique = true, nullable = false, length = 6)
    private int id;
    @ManyToOne
    private User user;
    @Column(nullable = false)
    @Temporal(TemporalType.TIMESTAMP)
    private Date date = new Date();
    @Column(nullable = false)
    private String title;
    @Column(nullable = false)
    private String content;
    @Column
    private int replynum = 0;


    public Poster(){

    }

    public Poster(User user, Date date, String title, String content, int replynum) {
        this.user = user;
        this.date = date;
        this.title = title;
        this.content = content;
        this.replynum = replynum;
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public int getReplynum() {
        return replynum;
    }

    public void setReplynum(int replynum) {
        this.replynum = replynum;
    }

    @Override
    public String toString() {
        return "Poster{" +
                "id=" + id +
                ", user=" + user +
                ", date=" + date +
                ", title='" + title + '\'' +
                ", content='" + content + '\'' +
                ", replynum=" + replynum +
                '}';
    }
}
