package com.sun.analyticplatform.model.entity;

import org.springframework.format.annotation.DateTimeFormat;

import javax.persistence.*;
import java.util.Date;
@Entity
@Table(name = "message")
public class Message {
    private static final long serialVersionUID = 4L;
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(unique = true, nullable = false, length = 6)
    private int id;
    @ManyToOne
    private User source;
    @ManyToOne
    private User destination;
    @Column(nullable = false)
    @Temporal(TemporalType.TIMESTAMP)
    private Date date = new Date();
    @Column
    private String content;
    @Column
    private boolean readed = false;
}
