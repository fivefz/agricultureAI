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
}
