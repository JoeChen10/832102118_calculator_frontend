Google C++ Style Guide
This document follows the guidelines outlined in the Google C++ Style Guide. Adhering to this style guide will ensure consistent and readable C++ code within our project.

1. Naming Conventions
Variable Names: Use snake_case for variable names. For example: user_age, total_count.
Function Names: Use snake_case for function names. For example: calculate_total(), process_data().
Class Names: Use CamelCase for class names. For example: UserInfo, DatabaseConnection.
Constants: Use all uppercase with underscores separating words. For example: MAX_BUFFER_SIZE, PI.

2. Indentation and Spacing
Use 2 spaces for indentation.
Use spaces around operators and after commas.
Avoid using tabs for indentation.

void example_function(int param1, int param2) {
  int result = param1 + param2;
  if (result > 0) {
    // Code block
  } else {
    // Code block
  }
}

3. Comments
Use // for single-line comments and place them above the code being described.
Use /* */ for multi-line comments.
// This is a single-line comment

/*
 * This is a multi-line comment.
 * It provides more detailed explanations.
 */
 
void example_function() {
  // Code here
}

4. Classes and Objects
Define only one class per file.
Define member functions and variables in the order: public, protected, and private.
Use explicit keyword for constructors with a single argument to prevent implicit type conversion.

class MyClass {
public:
  explicit MyClass(int value);
  void DoSomething();
private:
  int private_data_;
};

5. Other Guidelines
Prefer using nullptr over NULL or 0 for null pointers.
Use enum class instead of plain enum for strongly-typed enums.
Avoid using macros. Prefer const or constexpr variables instead.
