function calculateAwardPoints() {
   var awardPoints = 0;
   var userTickets = 4; // Code will be tested with other values as well
   
   if (userTickets >= 5) {
       awardPoints = 10;
   } else {
       awardPoints = userTickets;
   }
   
   return awardPoints;
}
