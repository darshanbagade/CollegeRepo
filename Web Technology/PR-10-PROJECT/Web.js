
let card = document.querySelector(".trend");
let card2 = document.getElementById("trendSec");
let about = document.querySelector(".about");
let contact = document.querySelector(".contact");


console.log(card);
let blog = document.querySelector(".trends");
let mainPage = document.querySelector(".main");

function homes(){
    mainPage.style.display="flex";
    card.style.display="block";
    card2.style.display="block";
    blog.style.display="block";
   about.style.display="none"


    
document.getElementById("blog").style.color="black";
document.getElementById("home").style.color="rgb(2, 173, 173)";
document.getElementById("shop").style.color="black";
document.getElementById("contact").style.color="black";
document.getElementById("about").style.color="black"


}
function shops(){
mainPage.style.display="none";
blog.style.display="none";
about.style.display="none"
card.style.display="block";
card2.style.display="block";

 
document.getElementById("blog").style.color="black";
document.getElementById("home").style.color="black";
document.getElementById("shop").style.color="rgb(2, 173, 173)";
document.getElementById("contact").style.color="black";
document.getElementById("about").style.color="black"


}

function blogs(){
    mainPage.style.display="none";
    card.style.display="none";
    card2.style.display="none";
   blog.style.display="block";
   about.style.display="none"
    

document.getElementById("blog").style.color="rgb(2, 173, 173)";
document.getElementById("home").style.color="black";
document.getElementById("shop").style.color="black";
document.getElementById("contact").style.color="black";
document.getElementById("about").style.color="black"

 



}

function abouts(){
    mainPage.style.display="none";
    card.style.display="none";
    card2.style.display="none";
   blog.style.display="none";
   about.style.display="block"

document.getElementById("blog").style.color="black";
document.getElementById("home").style.color="black";
document.getElementById("shop").style.color="black";
document.getElementById("contact").style.color="black";
document.getElementById("about").style.color="rgb(2, 173, 173)"

}

function contacts(){
    mainPage.style.display="none";
    card.style.display="none";
    card2.style.display="none";
   blog.style.display="none";
   about.style.display="none";
   contact.style.display="block"

document.getElementById("blog").style.color="black";
document.getElementById("home").style.color="black";
document.getElementById("shop").style.color="black";
document.getElementById("contact").style.color="black";
document.getElementById("about").style.color="black"
document.getElementById("contact").style.color="rgb(2, 173, 173)"

}

// cart

function show(img){
    let newImg = document.getElementById("newImg");
    console.log(img);
    newImg.src=img.src;

    mainPage.style.display="none";
    card.style.display="none";
    card2.style.display="none";
   blog.style.display="none";
   about.style.display="none";
   contact.style.display="none"
    document.querySelector(".cart").style.display="flex"
}


function addCart(){
    alert("Added To Cart");
    location.reload()
}



//for form validation
// Function to validate email format
function validateEmail(email) {
    const emailPattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
    return emailPattern.test(email);
}

// Function to validate phone number (Indian phone number example)
function validatePhone(phone) {
    const phonePattern = /^[6-9]\d{9}$/;  // Accepts 10 digit numbers starting from 6-9
    return phonePattern.test(phone);
}

// Handling form submission
document.getElementById("contactForm").addEventListener("submit", function(event) {
    const email = document.getElementById("email").value;
    const phone = document.getElementById("phone").value;
    
    let valid = true;
    
    // Email Validation
    if (!validateEmail(email)) {
        alert("Please enter a valid email address.");
        valid = false;
    }
    
    // Phone Validation
    if (!validatePhone(phone)) {
        alert("Please enter a valid phone number (10 digits).");
        valid = false;
    }

    // Prevent form submission if validation fails
    if (!valid) {
        event.preventDefault();
    }
});
