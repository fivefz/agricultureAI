package com.sun.analyticplatform.model.entity;

import org.springframework.format.annotation.DateTimeFormat;

import javax.persistence.*;
import java.util.Date;
@Entity
@Table(name = "notify")
public class Notify {
    private static final long serialVersionUID = 5L;
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(unique = true, nullable = false, length = 6)
    private int id;
    @ManyToOne
    private User publisher;
    @Column(nullable = false)
    @Temporal(TemporalType.TIMESTAMP)
    @OrderColumn
    private Date publishDate = new Date();
    @Column(nullable = false)
    private String title;
    @Column
    private String content;

    public static long getSerialVersionUID() {
        return serialVersionUID;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public User getPublisher() {
        return publisher;
    }

    public void setPublisher(User publisher) {
        this.publisher = publisher;
    }

    public Date getPublishDate() {
        return publishDate;
    }

    public void setPublishDate(Date publishDate) {
        this.publishDate = publishDate;
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

    @Override
    public String toString() {
        return "Notify{" +
                "id=" + id +
                ", publisher=" + publisher +
                ", publishDate=" + publishDate +
                ", title='" + title + '\'' +
                ", content='" + content + '\'' +
                '}';
    }
}
