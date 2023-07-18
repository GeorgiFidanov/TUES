package dxc.add.repository;

import dxc.add.model.CategoryEntity;
import dxc.add.model.LocationEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface LocationRepository extends JpaRepository<LocationEntity, Integer> {
}
