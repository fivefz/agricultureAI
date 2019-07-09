package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Message;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;

public interface MessageRepository extends JpaRepository<Message,Long> {
    List<Message> findAllByDestination_IdAndReadedIsFalse(int dest_id);
    List<Message> findAllBySource_IdAndAndDestination_Id(int source_id,int dest_id);
}
