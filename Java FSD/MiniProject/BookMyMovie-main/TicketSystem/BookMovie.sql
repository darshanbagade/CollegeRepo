CREATE DATABASE bookmymovie;

USE bookmymovie;

CREATE TABLE movies (
  id INT AUTO_INCREMENT PRIMARY KEY,
  movie_name VARCHAR(255) NOT NULL,
  ticket_price INT NOT NULL,
  timing VARCHAR(18) NOT NULL,
  mlanguage VARCHAR(32) NOT NULL
);

CREATE TABLE seats (
  id INT AUTO_INCREMENT PRIMARY KEY,
  avail BOOLEAN,
  seat_number INT NOT NULL,
  movie_id INT NOT NULL,
  FOREIGN KEY (movie_id) REFERENCES movies(id)
);

CREATE TABLE bookings (
  id INT AUTO_INCREMENT PRIMARY KEY,
  movie_id INT NOT NULL,
  billDate DATE,
  billAmount int,
  FOREIGN KEY (movie_id) REFERENCES movies(id)
);

INSERT INTO movies
	VALUES
    (1, "__", 0, "__", "__"),
    (2, "__", 0, "__", "__"),
    (3, "__", 0, "__", "__");


UPDATE seats
	SET
    avail = 1
    WHERE movie_id = 1 OR movie_id = 2 OR movie_id = 3;
    

