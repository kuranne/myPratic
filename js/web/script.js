document.writeln('<h4>Script Loaded!</h4>')

function changeText() {
    document.getElementById("to-change-text").innerText = "Yay, You Change THISS!";
}

function darkMode() {
    document.body.classList.toggle("dark")
}