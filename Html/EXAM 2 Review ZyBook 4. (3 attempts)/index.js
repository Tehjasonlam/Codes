function parseScores(scoresString) {
    // Split the scoresString into an array of score strings
    return scoresString.split(' ');
}

// Test the function
const scoresString = "45 78 98 83 86 99 90 59";
const scoresArray = parseScores(scoresString);
console.log(scoresArray); // Output: ["45", "78", "98", "83", "86", "99", "90", "59"]
