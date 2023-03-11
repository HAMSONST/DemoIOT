console.log("inicio del programa")

var contador = 0;
var myButton = document.getElementById("boton");
var myText = document.getElementById("texto");

myButton.onclick = function(){
    contador++;
    if (contador > 9) {
        contador = 0
    }
    myText.textContent = contador;
    
}   

    