package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Reply;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;
public interface ReplyRepository extends JpaRepository<Reply,Long> {
}