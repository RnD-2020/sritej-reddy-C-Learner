function glow(e) {
    "use strict";
    var audio = document.getElementById("audio");
    audio.play();
    var keycode = document.getElementById(window.event.keyCode);

    //the below if condition is to check whether the pressed key is alt / ctrl / shift / enter because if those keys are pressed we need to glow both keys of them

    if (keycode.className == "enter" || keycode.className == "shift" || keycode.className == "alt" || keycode.className == "ctrl") {
        keycode = document.getElementsByClassName(keycode.className);
        keycode[0].style.backgroundColor = "red";
        keycode[1].style.backgroundColor = "red";
        keycode[0].style.transform = "translateY(310px)";
        keycode[1].style.transform = "translateY(310px)";
    } else {
        keycode.style.backgroundColor = "red";
        keycode.style.transform = "translateY(310px)";
    }
    e.preventDefault();
}
window.addEventListener("keydown", glow, false);
