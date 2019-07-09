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
    private User source;
    @Column(nullable = false)
    @Temporal(TemporalType.TIMESTAMP)
    @OrderColumn
    private Date date = new Date();
    @Column(nullable = false)
    private String title;
    @Column
    private String content;
}
