USE appliances;

DELIMITER $$
CREATE TRIGGER new_purchase
BEFORE INSERT ON purchase_history
FOR EACH ROW
BEGIN
	DECLARE item_old_count INT default 0;
    
    SET item_old_count = (SELECT `count` FROM appliances WHERE id = NEW.item LIMIT 1);
    
    IF (item_old_count >= NEW.count) THEN
		UPDATE appliances SET `count` = `count` - NEW.count WHERE id = NEW.item;
	ELSE
		UPDATE appliances SET `count` = 0 WHERE id = NEW.item;
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'You want too much items';
	END IF;
END$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER update_customer_points
AFTER INSERT ON purchase_history
FOR EACH ROW
BEGIN
	-- DECLARE items_purchased ; 
    UPDATE customers SET `points` = `points` WHERE id = NEW.customer;
END$$
DELIMITER ;

-- show triggers;