package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Poster;
import org.springframework.data.jpa.repository.JpaRepository;

public interface PosterRepository extends JpaRepository<Poster,Long> {
}
