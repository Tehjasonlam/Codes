window.addEventListener("DOMContentLoaded", domLoaded);

function domLoaded() {
  celsiusInput = document.getElementById("cInput");
  fahrenheitInput = document.getElementById("fInput");
  convertButton = document.getElementById("convertButton");
  errorMessage = document.getElementById("errorMessage");
  weatherImage = document.getElementById("weatherImage");

  convertButton.addEventListener("click", function () {
    let celsius = celsiusInput.value;
    let fahrenheit = fahrenheitInput.value;
    if (isNaN(celsius))
      errorMessage.innerHTML = celsiusInput.value + " is not a number";
    else if (isNaN(fahrenheit))
      errorMessage.innerHTML = fahrenheitInput.value + " is not a number";
    else {
      errorMessage.innerHTML = "";
      if (celsius == "") celsiusInput.value = convertFtoC(fahrenheit);
      else fahrenheitInput.value = convertCtoF(celsius);
      if (parseFloat(fahrenheitInput.value) < 32) weatherImage.src = "cold.png";
      else if (parseFloat(fahrenheitInput.value) <= 50)
        weatherImage.src = "cool.png";
      else weatherImage.src = "warm.png";
    }
  });

  celsiusInput.addEventListener("input", function () {
    fahrenheitInput.value = "";
  });
  fahrenheitInput.addEventListener("input", function () {
    celsiusInput.value = "";
  });
}

function convertCtoF(degreesCelsius) {
  return (degreesCelsius * 9) / 5 + 32;
}

function convertFtoC(degreesFahrenheit) {
  return ((degreesFahrenheit - 32) * 5) / 9;
}
