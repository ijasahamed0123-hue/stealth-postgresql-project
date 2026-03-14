CREATE TABLE games (
    game_id SERIAL PRIMARY KEY,
    game_name VARCHAR(100) NOT NULL,
    genre VARCHAR(50),
    release_year INTEGER,
    developer VARCHAR(100),
    price NUMERIC(8,2),
    rating DECIMAL(3,1),
    multiplayer BOOLEAN
);