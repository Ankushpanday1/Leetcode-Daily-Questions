SELECT S.id,
       IFNULL(
           IF(S.id % 2 = 0,
              (SELECT student FROM Seat WHERE id = S.id - 1),
              (SELECT student FROM Seat WHERE id = S.id + 1)
           ),
           S.student
       ) AS student
FROM Seat S
ORDER BY S.id;