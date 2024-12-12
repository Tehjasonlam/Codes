function calcWordFrequencies() {
    let text = prompt("Enter a list of words separated by spaces:");
  
    let words = text.split(" ");
  
    let frequencies = {};
  
    for (let i = 0; i < words.length; i++) {
      let word = words[i];
      if (frequencies[word]) {
        frequencies[word]++;
      } else {
        frequencies[word] = 1;
      }
    }
  
    for (let i = 0; i < words.length; i++) {
      console.log(words[i] + " " + frequencies[words[i]]);
    }
  }