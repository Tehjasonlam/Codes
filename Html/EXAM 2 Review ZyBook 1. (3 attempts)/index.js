function calculateAwardPoints() {
   var awardPoints = 0;
   var enteredNum = 5; // Initial value, can be changed
   
   while (enteredNum < 60) {
      enteredNum *= 3; // Multiply enteredNum by 3
      console.log(enteredNum); // Display the result after each multiplication
   }
}

// Test the function
calculateAwardPoints();