package com.sun.analyticplatform.model.DAO;

import com.sun.analyticplatform.model.entity.Consult;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface ConsultRepository extends JpaRepository<Consult,Long> {
    List<Consult> findAllByToId(int id);
    List<Consult> findAllByFromId(int id);
    List<Consult> findByFromIdAndToId(int from_id,int to_id);
    Consult findById(int id);

}
