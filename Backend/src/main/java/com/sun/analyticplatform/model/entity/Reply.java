package com.sun.analyticplatform.model.entity;


import javax.persistence.*;
import java.util.Date;
@Entity
@Table(name = "reply")
public class Reply {
    private static final long serialVersionUID = 2L;
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(unique = true, nullable = false, length = 6)
    private int id;
    @ManyToOne
    private Poster poster;
    @ManyToOne
    private User user;
    @Column(nullable = false)
    @Temporal(TemporalType.TIMESTAMP)
    private Date date;
    @Column
    private String content;

    public Reply(){

    }
    public Reply(Poster poster, User user, Date date, String content) {
        this.poster = poster;
        this.user = user;
        this.date = date;
        this.content = content;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Poster getPoster() {
        return poster;
    }

    public void setPoster(Poster poster) {
        this.poster = poster;
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

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return "Reply{" +
                "id=" + id +
                ", poster=" + poster +
                ", user=" + user +
                ", date=" + date +
                ", content='" + content + '\'' +
                '}';
    }
}
