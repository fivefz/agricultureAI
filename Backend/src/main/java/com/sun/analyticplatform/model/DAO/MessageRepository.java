package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Message;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;

public interface MessageRepository extends JpaRepository<Message,Long> {
    List<Message> findAllByToId(int to_id);
    List<Message> findAllByFromId(int from_id);
    Message findById(int id);

}
