CREATE TABLE employees (
    emp_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    age INTEGER,
    department VARCHAR(50),
    salary NUMERIC(10,2),
    email TEXT,
    hire_date DATE,
    is_active BOOLEAN
);