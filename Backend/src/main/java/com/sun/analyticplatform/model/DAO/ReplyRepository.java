package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Poster;
import com.sun.analyticplatform.model.entity.Reply;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;
import java.util.Optional;

public interface ReplyRepository extends JpaRepository<Reply,Long> {
    List<Reply> findAllByPoster_Id(int poster_id);
    List<Reply> findAllByUser(int user_id);
}
