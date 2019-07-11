package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Notify;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface NotifyRepository extends JpaRepository<Notify,Long> {
    List<Notify> findAll();
    Notify findById(int id);
}
