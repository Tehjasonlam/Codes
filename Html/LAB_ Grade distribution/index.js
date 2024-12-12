function parseScores(scoresString) {
    return scoresString.split(" ");
  }
  
  function buildDistributionArray(scoresArray) {
    let a = 0;
    let b = 0;
    let c = 0;
    let d = 0;
    let f = 0;
    for (let i = 0; i < scoresArray.length; i++) {
      if (scoresArray[i] >= 90) a += 1;
      else if (scoresArray[i] >= 80) b += 1;
      else if (scoresArray[i] >= 70) c += 1;
      else if (scoresArray[i] >= 60) d += 1;
      else f += 1;
    }
    return [a, b, c, d, f];
  }
  
  function setTableContent(userInput) {
    if (userInput.length == 0) {
      let table = document.getElementById("distributionTable");
      table.innerHTML = "<tr><td>No graph to display</td></tr>";
    } else {
      let scoresArray = parseScores(userInput);
      let distributionArray = buildDistributionArray(scoresArray);
      let table = document.getElementById("distributionTable");
      table.innerHTML =
        '<tr><td><div style="height:' +
        distributionArray[0] * 10 +
        'px" class="bar0"></div></td><td><div style="height:' +
        distributionArray[1] * 10 +
        'px" class="bar1"></div></td><td><div style="height:' +
        distributionArray[2] * 10 +
        'px" class="bar2"></div></td><td><div style="height:' +
        distributionArray[3] * 10 +
        'px"  class="bar3"></div></td><td><div style="height:' +
        distributionArray[4] * 10 +
        'px" class="bar4"></div></td></tr><tr><td>A</td><td>B</td><td>C</td><td>D</td><td>F</td></tr><tr><td>' +
        distributionArray[0] +
        "</td><td>" +
        distributionArray[1] +
        "</td><td>" +
        distributionArray[2] +
        "</td><td>" +
        distributionArray[3] +
        "</td><td>" +
        distributionArray[4] +
        "</td></tr>";
    }
  }
  
  function bodyLoaded() {
    // The argument passed to writeTableContent can be changed for
    // testing purposes
    setTableContent("45 78 98 83 86 99 90 59");
  }
  