function checkForm() {
  // Perform input validation 
  const fullName = document.getElementById("fullName");
  const email = document.getElementById("email");
  const password = document.getElementById("password");
  const passwordConfirm = document.getElementById("passwordConfirm");
  const formErrors = document.getElementById("formErrors");

  formErrors.classList.add("hide");
  formErrors.innerHTML = ""; // Clear any previous error messages

  let errors = false; // Variable to track if there are any errors

  if (fullName.value.length < 1) {
    formErrors.classList.remove("hide");
    fullName.classList.add("error");
    formErrors.innerHTML += "<li>Missing full name.</li>";
    errors = true;
  } else {
    fullName.classList.remove("error");
  }

  const reemail = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,5}$/;
  if (!reemail.test(email.value)) {
    formErrors.classList.remove("hide");
    email.classList.add("error");
    formErrors.innerHTML += "<li>Invalid or missing email address.</li>";
    errors = true;
  } else {
    email.classList.remove("error");
  }

  if (password.value.length < 10 || password.value.length > 20) {
    formErrors.classList.remove("hide");
    password.classList.add("error");
    html += "<li>Password must be between 10 and 20 characters.</li>";
    errors = true; // Mark as error
  } else {
    password.classList.remove("error");
  }

  if (!/[a-z]/.test(password.value)) {
    formErrors.classList.remove("hide");
    password.classList.add("error");
    formErrors.innerHTML += "<li>Password must contain at least one lowercase character.</li>";
    errors = true;
  } else {
    password.classList.remove("error");
  }

  if (!/[A-Z]/.test(password.value)) {
    formErrors.classList.remove("hide");
    password.classList.add("error");
    formErrors.innerHTML += "<li>Password must contain at least one uppercase character.</li>";
    errors = true;
  } else {
    password.classList.remove("error");
  }

  if (!/[0-9]/.test(password.value)) {
    formErrors.classList.remove("hide");
    password.classList.add("error");
    formErrors.innerHTML += "<li>Password must contain at least one digit.</li>";
    errors = true;
  } else {
    password.classList.remove("error");
  }

  if (password.value !== passwordConfirm.value) {
    formErrors.classList.remove("hide");
    passwordConfirm.classList.add("error");
    formErrors.innerHTML += "<li>Password and confirmation password don't match.</li>";
    errors = true;
  } else {
    passwordConfirm.classList.remove("error");
  }

  // If there are errors, prevent form submission
  if (errors) {
    event.preventDefault(); // Prevent form submission
  }
}
