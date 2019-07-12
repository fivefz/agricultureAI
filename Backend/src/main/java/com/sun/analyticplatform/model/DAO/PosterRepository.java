package com.sun.analyticplatform.model.DAO;
import java.util.List;
import com.sun.analyticplatform.model.entity.Poster;
import org.springframework.data.jpa.repository.JpaRepository;

public interface PosterRepository extends JpaRepository<Poster,Long> {
    List<Poster> findAllByUser(int user_id);
    Poster findById(int id);
}
