var btn = document.getElementById('btn5');
btn.onclick = function() {
    var b1 = document.getElementById('btn1');
    var b2 = document.getElementById('btn2');
    var b3 = document.getElementById('btn3');
    var b4 = document.getElementById('btn4');
    var b6 = document.getElementById('btn6');
    var b7 = document.getElementById('btn7');
    var b8 = document.getElementById('btn8');
    var b9 = document.getElementById('btn9');

    let i1 = Number(b1.innerHTML);
    let i2 = Number(b2.innerHTML);
    let i3 = Number(b3.innerHTML);
    let i4 = Number(b4.innerHTML);
    let i6 = Number(b6.innerHTML);
    let i7 = Number(b7.innerHTML);
    let i8 = Number(b8.innerHTML);
    let i9 = Number(b9.innerHTML);

    b1.innerHTML = i4;
    b2.innerHTML = i1;
    b3.innerHTML = i2;
    b6.innerHTML = i3;
    b9.innerHTML = i6;
    b8.innerHTML = i9;
    b7.innerHTML = i8;
    b4.innerHTML = i7;
};
