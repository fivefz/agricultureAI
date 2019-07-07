package com.sun.analyticplatform.model.entity;

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
    private Date date;
    @Column
    private String title;
    @Column
    private String content;
}
