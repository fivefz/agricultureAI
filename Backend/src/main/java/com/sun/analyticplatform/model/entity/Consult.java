package com.sun.analyticplatform.model.entity;

import javax.persistence.*;
import java.util.Date;

@Entity
@Table(name = "consult")
public class Consult {
    private static final long serialVersionUID = 4L;
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(unique = true, nullable = false, length = 6)
    private int id;
    @ManyToOne
    private User from;
    @ManyToOne
    private User to;
    @Column(nullable = false)
    @Temporal(TemporalType.TIMESTAMP)
    private Date date = new Date();
    @Column
    private String question;
    @Column
    private String reply;
    @Column
    private boolean readed = false;

    public Consult(){

    }

    public Consult(User from, User to, Date date, String question, String reply, boolean readed) {
        this.from = from;
        this.to = to;
        this.date = date;
        this.question = question;
        this.reply = reply;
        this.readed = readed;
    }

    public static long getSerialVersionUID() {
        return serialVersionUID;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public User getFrom() {
        return from;
    }

    public void setFrom(User from) {
        this.from = from;
    }

    public User getTo() {
        return to;
    }

    public void setTo(User to) {
        this.to = to;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public String getQuestion() {
        return question;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public String getReply() {
        return reply;
    }

    public void setReply(String reply) {
        this.reply = reply;
    }

    public boolean isReaded() {
        return readed;
    }

    public void setReaded(boolean readed) {
        this.readed = readed;
    }

    @Override
    public String toString() {
        return "Consult{" +
                "id=" + id +
                ", from=" + from +
                ", to=" + to +
                ", date=" + date +
                ", question='" + question + '\'' +
                ", reply='" + reply + '\'' +
                ", readed=" + readed +
                '}';
    }
}
