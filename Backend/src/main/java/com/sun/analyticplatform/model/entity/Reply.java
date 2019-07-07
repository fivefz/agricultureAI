package com.sun.analyticplatform.model.entity;

import javax.persistence.*;
import java.util.Date;

public class Reply {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(unique = true, nullable = false, length = 6)
    private int id;
    @ManyToOne
    private Poster poster;
    @ManyToOne
    private User user;
    @Column(nullable = false)
    private Date date;
    @Column
    private String content;
}
