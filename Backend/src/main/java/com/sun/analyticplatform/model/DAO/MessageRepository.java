package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Message;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MessageRepository extends JpaRepository<Message,Long> {
}
