function checkForm() {
   // TODO: Perform input validation
   const fullName = document.getElementById("fullName");
   const email = document.getElementById("email");
   const password = document.getElementById("password");
   const passwordConfirm = document.getElementById("passwordConfirm");
   const formErrors = document.getElementById("formErrors");
 
   formErrors.style.display = "none";
 
   let html = "<ul>";
 
   if (fullName.value.length < 1) {
     formErrors.style.display = "block";
     fullName.style.border = "2px solid red";
     html += "<li>Missing full name.</li>";
   } else {
     fullName.style.border = "1px solid #aaa";
   }
 
   const reemail = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,5}$/;
   if (!reemail.test(email.value)) {
     formErrors.style.display = "block";
     email.style.border = "2px solid red";
     html += "<li>Invalid or missing email address.</li>";
   } else {
     email.style.border = "1px solid #aaa";
   }
 
   if (password.value.length < 10 || password.value.length > 20) {
     formErrors.style.display = "block";
     password.style.border = "2px solid red";
     html += "<li>Password must be between 10 and 20 characters.</li>";
   } else {
     password.style.border = "1px solid #aaa";
   }
 
   if (!/[a-z]/.test(password.value)) {
     formErrors.style.display = "block";
     password.style.border = "2px solid red";
     html += "<li>Password must contain at least one lowercase character.</li>";
   } else {
     password.style.border = "1px solid #aaa";
   }
 
   if (!/[A-Z]/.test(password.value)) {
     formErrors.style.display = "block";
     password.style.border = "2px solid red";
     html += "<li>Password must contain at least one uppercase character.</li>";
   } else {
     password.style.border = "1px solid #aaa";
   }
 
   if (!/[0-9]/.test(password.value)) {
     formErrors.style.display = "block";
     password.style.border = "2px solid red";
     html += "<li>Password must contain at least one digit.</li>";
   } else {
     password.style.border = "1px solid #aaa";
   }
 
   if (password.value !== passwordConfirm.value) {
     formErrors.style.display = "block";
     passwordConfirm.style.border = "2px solid red";
     html += "<li>Password and confirmation password don't match.</li>";
   } else {
     passwordConfirm.style.border = "1px solid #aaa";
   }
 
   html += "</ul>";
   formErrors.innerHTML = html;
 }
 
 document.getElementById("submit").addEventListener("click", function (event) {
   checkForm();
 
   // Prevent default form action. DO NOT REMOVE THIS LINE
   event.preventDefault();
 });
 