# Write your MySQL query statement below
#easy peasy
SELECT e.name, b.bonus FROM Employee e LEFT JOIN Bonus b 
ON e.empId = b.empId WHERE b.bonus < 1000 OR b.bonus IS NULL;


#LEFT JOIN includes all records from the Employee table. If an employee does not have a corresponding record in the Bonus table, the bonus will be NULL.