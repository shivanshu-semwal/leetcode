SELECT name as Employee FROM employee e
WHERE e.salary > (SELECT salary FROM employee WHERE id = e.managerId);
