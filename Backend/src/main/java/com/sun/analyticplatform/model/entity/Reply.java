package com.sun.analyticplatform.model.entity;

import org.springframework.format.annotation.DateTimeFormat;

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
}
