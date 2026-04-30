# Default Arguments, Reference Variables & Call by Reference in C++







## 1. What are Default Arguments?

Default arguments are values assigned to function parameters during function declaration.  
If the user does not pass a value while calling the function, the compiler automatically uses the default value.

## Purpose / Use

- Reduces need for multiple overloaded functions  
- Makes functions flexible   
- Useful when some parameters are optional

## How It Works

If an argument is provided, that value is used.  
If not provided, the default value is taken.

Example:

- `int add(int a, int b=1)`
- `add(10)` → uses default value of b, answer will be 11 

## Important Rules

- Default arguments are usually written from **right to left** parameters.  
- Once a parameter has default value, parameters after it should also have default values.
- Usually declared in function prototype.

---
<br>

## 2. What is a Reference Variable?

A reference variable is another name (alias) for an existing variable.

It does not create a new variable.  
It refers to the same memory location as the original variable.

## Purpose / Use

- Avoid copying data  
- Easy access using another name  
- Used heavily in function parameters  
- Improves performance for large objects

## How It Works

If one name changes the value, the other name also reflects the change because both refer to same data.

Example:

- int x;
- int &a = x;


---
<br>


## 3. What is Call by Reference?

Call by Reference means passing arguments to a function using reference variables.

Instead of sending a copy of data, the function receives the original variable itself.

## Purpose / Use

- Function can modify original variables  
- No extra copy is created  
- Better performance  
- Useful for swapping values, updating data, editing objects

---
<br>

# Function Overloading in C++

Function Overloading is a concept of **Compile Time Polymorphism** in C++.

### Polymorphism in C++

Polymorphism in C++ is mainly divided into two types:

1. **Compile Time Polymorphism**
   - Function Overloading  
   - Operator Overloading  

2. **Run Time Polymorphism**
   - Virtual Functions  

### What is Function Overloading?

Function Overloading allows multiple functions to have the **same name** but with **different parameters** (different number, type, or order of arguments).

It helps improve code readability and makes functions easier to use when performing similar tasks with different inputs.

### How Overloading is Resolved

The compiler decides which overloaded function to call **at compile time** based on:

- Number of arguments  
- Type of arguments  
- Order of arguments  

This process is known as **Compile Time Binding** or **Static Binding**.
