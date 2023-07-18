package dxc.add.repository;

import dxc.add.model.AddTypeEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface AddTypeRepository extends JpaRepository<AddTypeEntity, Integer> {
}
