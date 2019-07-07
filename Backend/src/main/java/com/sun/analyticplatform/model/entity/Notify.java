package com.sun.analyticplatform.model.entity;

import javax.persistence.*;
import java.util.Date;

public class Notify {
    private static final long serialVersionUID = 5L;
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(unique = true, nullable = false, length = 6)
    private int id;
    @ManyToOne
    private User source;
    @ManyToOne
    private User destination;
    @Column(nullable = false)
    private Date date = new Date();
    @Column
    private String content;
}
