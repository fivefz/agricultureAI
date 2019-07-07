package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Notify;
import org.springframework.data.jpa.repository.JpaRepository;

public interface NotifyRepository extends JpaRepository<Notify,Long> {
}
